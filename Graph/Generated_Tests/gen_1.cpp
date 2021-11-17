#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>

// N_SIZE > 2
#define N_SIZE 10000

void print_left(std::ofstream& out, int x, int y)
{
    int i = x;
    while(i != y)
    {
        std::cout << i << ' ';
        --i;
        if(i < 0)
        {
            i = N_SIZE - 1;
        }
    }
    std::cout << y << ' ';
}

void print_right(std::ofstream& out, int x, int y)
{
    int i = x;
    while(i != y)
    {
        out << i << ' ';
        ++i;
        if(i >= N_SIZE)
        {
            i = 0;
        }
    }
    out << y << ' ';
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Path for generating files was not given" << std::endl;
        exit(1);
    }
    std::string path = argv[1];
    std::string inputname = path + "/gen_test_1.in.txt";
    std::ofstream input(inputname, std::ios_base::trunc);
    if(input.fail())
	{
		std::cerr << "Something went wrong while opening (creating) input file." << std::endl;
		exit(1);
	}
    std::string outputname = path + "/gen_test_1.out.txt";
    std::ofstream output(outputname, std::ios_base::trunc);
    if(output.fail())
	{
		std::cerr << "Something went wrong while opening (creating) output file." << std::endl;
		exit(1);
	}
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, N_SIZE - 1);
    int x = dist6(rng);
    int y = dist6(rng);
    input << N_SIZE << ' ' << N_SIZE << std::endl;
    for(int i = 0; i < N_SIZE - 1; ++i)
    {
        input << i << ' ' << i + 1 << ' ' << 1 << std::endl;
    }
    input << N_SIZE - 1 << ' ' << 0 << ' ' << 1 << std::endl;
    input << x << ' ' << y << std::flush;
    int right_rot_dist = std::abs(x - y);
    int left_rot_dist = N_SIZE - std::abs(x - y);
    int dist = std::min(right_rot_dist, left_rot_dist);
    output << "Shortest distance: " <<  dist << std::endl;
    if(x <= y)
    {
        if(right_rot_dist == left_rot_dist)
        {
            if(x == 0)
            {
                print_right(output, x, y);
                print_left(output, x, y);
            }
            else
            {
                print_left(output, x, y);
                print_right(output, x, y);
            }
        }
        else if(right_rot_dist > left_rot_dist)
        {
            print_left(output, x, y);
        }
        else
        {
            print_right(output, x, y);
        }
    }
    else
    {
        if(right_rot_dist == left_rot_dist)
        {
            if(x == 0)
            {
                print_left(output, x, y);
                print_right(output, x, y);
            }
            else
            {
                print_right(output, x, y);
                print_left(output, x, y);
            }
        }
        else if(right_rot_dist > left_rot_dist)
        {
            print_right(output, x, y);
        }
        else
        {
            print_left(output, x, y);
        }
    }
    output << std::endl;
    return 0;
}