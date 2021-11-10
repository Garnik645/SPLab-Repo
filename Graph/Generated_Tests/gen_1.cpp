#include <iostream>
#include <random>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <cerrno>

// N_SIZE > 2
#define N_SIZE 10000

void print_left(int x, int y)
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

void print_right(int x, int y)
{
    int i = x;
    while(i != y)
    {
        std::cout << i << ' ';
        ++i;
        if(i >= N_SIZE)
        {
            i = 0;
        }
    }
    std::cout << y << ' ';
}

int main()
{
    int input = open("gen_test_1.in.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if(input < 0)
	{
		std::cerr << "Something went wrong while opening (creating) input file. Error " << errno << std::endl;
		exit(errno);
	}
    int output = open("gen_test_1.out.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if(output < 0)
	{
		std::cerr << "Something went wrong while opening (creating) output file. Error " << errno << std::endl;
		exit(errno);
	}
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 9998);
    int x = dist6(rng);
    int y = dist6(rng);
    dup2(input, 1);
    std::cout << N_SIZE << ' ' << N_SIZE << std::endl;
    for(int i = 0; i < N_SIZE - 1; ++i)
    {
        std::cout << i << ' ' << i + 1 << ' ' << 1 << std::endl;
    }
    std::cout << N_SIZE - 1 << ' ' << 0 << ' ' << 1 << std::endl;
    std::cout << x << ' ' << y << std::flush;
    dup2(output, 1);
    int right_rot_dist = std::abs(x - y);
    int left_rot_dist = N_SIZE - std::abs(x - y);
    int dist = std::min(right_rot_dist, left_rot_dist);
    std::cout << "Shortest distance: " <<  dist << std::endl;
    if(x <= y)
    {
        if(right_rot_dist == left_rot_dist)
        {
            if(x == 0)
            {
                print_right(x, y);
                print_left(x, y);
            }
            else
            {
                print_left(x, y);
                print_right(x, y);
            }
        }
        else if(right_rot_dist > left_rot_dist)
        {
            print_left(x, y);
        }
        else
        {
            print_right(x, y);
        }
    }
    else
    {
        if(right_rot_dist == left_rot_dist)
        {
            if(x == 0)
            {
                print_left(x, y);
                print_right(x, y);
            }
            else
            {
                print_right(x, y);
                print_left(x, y);
            }
        }
        else if(right_rot_dist > left_rot_dist)
        {
            print_right(x, y);
        }
        else
        {
            print_left(x, y);
        }
    }
    std::cout << std::endl;
    return 0;
}