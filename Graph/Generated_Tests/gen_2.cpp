#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

// N_SIZE >= 100
#define N_SIZE 10000

void find_path(int current, int end, std::vector<int>& buffer, std::ofstream& out, int root)
{
    buffer.push_back(current);
    if(current == end)
    {
        for(size_t i = 0; i < buffer.size(); ++i)
        {
            out << buffer[i] << ' ';
        }
        out << std::endl;
    }
    else
    {
        if(current / root > end / root)
        {
            find_path(current - root, end, buffer, out, root);
        }
        if(current % root > end % root)
        {
            find_path(current - 1, end, buffer, out, root);
        }
        if(current % root < end % root)
        {
            find_path(current + 1, end, buffer, out, root);
        }
        if(current / root < end / root)
        {
            find_path(current + root, end, buffer, out, root);
        }
    }
    buffer.pop_back();
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Path for generating files was not given" << std::endl;
        exit(1);
    }
    std::string path = argv[1];
    std::string inputname = path + "/gen_test_2.in.txt";
    std::ofstream input(inputname, std::ios_base::trunc);
    if(input.fail())
	{
		std::cerr << "Something went wrong while opening (creating) input file." << std::endl;
		exit(1);
	}
    std::string outputname = path + "/gen_test_2.out.txt";
    std::ofstream output(outputname, std::ios_base::trunc);
    if(output.fail())
	{
		std::cerr << "Something went wrong while opening (creating) output file." << std::endl;
		exit(1);
	}
    int edges = 0;
    int root = std::sqrt(N_SIZE);
    for(int i = 0; i < N_SIZE; ++i)
    {
        if(i >= root)
        {
            ++edges;
        }
        if(i % root != 0)
        {
            ++edges;
        }
    }
    input << N_SIZE << ' ' << edges << std::endl;
    for(int i = 0; i < N_SIZE; ++i)
    {
        if(i >= root)
        {
            input << i << ' ' << i - root << ' ' << 1 << std::endl;
        }
        if(i % root != 0)
        {
            input << i << ' ' << i - 1 << ' ' << 1 << std::endl;
        }
    }
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> start_rand(0, N_SIZE - 1);
    std::uniform_int_distribution<std::mt19937::result_type> end_rand(0, 800);
    int x = start_rand(rng);
    int y = end_rand(rng);
    y -= 400;
    y += x;
    if(y < 0)
    {
        y = 0;
    }
    if(y >= N_SIZE)
    {
        y = N_SIZE - 1;
    }
    input << x << ' ' << y << std::flush;
    output << "Shortest distance: " <<  std::abs(x % root - y % root) + std::abs(x / root - y / root) << std::endl;
    std::vector<int> buffer;
    find_path(x, y, buffer, output, root);
    return 0;
}