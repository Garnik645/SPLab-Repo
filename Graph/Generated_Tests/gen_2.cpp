#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <cerrno>

// N_SIZE >= 100
#define N_SIZE 10000

void find_path(int current, int end, std::vector<int>& out, int root)
{
    out.push_back(current);
    if(current == end)
    {
        for(size_t i = 0; i < out.size(); ++i)
        {
            std::cout << out[i] << ' ';
        }
        std::cout << std::endl;
    }
    else
    {
        if(current / root > end / root)
        {
            find_path(current - root, end, out, root);
        }
        if(current % root > end % root)
        {
            find_path(current - 1, end, out, root);
        }
        if(current % root < end % root)
        {
            find_path(current + 1, end, out, root);
        }
        if(current / root < end / root)
        {
            find_path(current + root, end, out, root);
        }
    }
    out.pop_back();
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
    int input = open(inputname.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if(input < 0)
	{
		std::cerr << "Something went wrong while opening (creating) input file. Error " << errno << std::endl;
		exit(errno);
	}
    std::string outputname = path + "/gen_test_2.out.txt";
    int output = open(outputname.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if(output < 0)
	{
		std::cerr << "Something went wrong while opening (creating) output file. Error " << errno << std::endl;
		exit(errno);
	}
    dup2(input, 1);
    int edges = 0;
    int root = std::sqrt(N_SIZE);
    for(int i = 0; i < N_SIZE; ++i)
    {
        if(i >= root) ++edges;
        if(i % root != 0) ++edges;
    }
    std::cout << N_SIZE << ' ' << edges << std::endl;
    for(int i = 0; i < N_SIZE; ++i)
    {
        if(i >= root) std::cout << i << ' ' << i - root << ' ' << 1 << std::endl;
        if(i % root != 0) std::cout << i << ' ' << i - 1 << ' ' << 1 << std::endl;
    }
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> start_rand(0, N_SIZE - 1);
    std::uniform_int_distribution<std::mt19937::result_type> end_rand(0, 800);
    int x = start_rand(rng);
    int y = end_rand(rng);
    y -= 400;
    y += x;
    if(y < 0) y = 0;
    if(y >= N_SIZE) y = N_SIZE - 1;
    std::cout << x << ' ' << y << std::flush;
    dup2(output, 1);
    std::cout << "Shortest distance: " <<  std::abs(x % root - y % root) + std::abs(x / root - y / root) << std::endl;
    std::vector<int> out;
    find_path(x, y, out, root);
    return 0;
}