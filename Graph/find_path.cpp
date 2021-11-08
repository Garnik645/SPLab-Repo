#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

struct Path;
struct Node;

struct Node
{
    size_t index;
    std::vector<Path> edges;
    int shortest = std::numeric_limits<int>::max();
    std::vector<Node*> prev;
};

struct Path
{
    int dist;
    Node* node_ptr;

    Path(int x = 0, Node* ptr = nullptr) : dist(x), node_ptr(ptr) {} 
    
    friend bool operator>(const Path& lhs, const Path& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

void print_paths(Node* start, Node* current, std::vector<size_t>& path, std::vector<std::string>& output)
{
    if(current == start)
    {
        std::string str = "";
        str += std::to_string(start->index) + ' ';
        for(int i = path.size() - 1; i >= 0; --i)
        {
            str += std::to_string(path[i]) + ' ';
        }
        output.push_back(str);
        return;
    }
    for(size_t i = 0; i < current->prev.size(); ++i)
    {
        path.push_back(current->index);
        print_paths(start, current->prev[i], path, output);
        path.pop_back();
    }
}

void dijkstra(std::priority_queue<Path, std::vector<Path>, std::greater<Path>>& update_queue)
{
    Path path = update_queue.top();
    update_queue.pop();
    for(size_t i = 0; i < path.node_ptr->edges.size(); ++i)
    {
        Path next_path = path.node_ptr->edges[i];
        if(path.node_ptr->shortest + next_path.dist < next_path.node_ptr->shortest)
        {
            next_path.node_ptr->shortest = path.node_ptr->shortest + next_path.dist;
            next_path.node_ptr->prev.clear();
            update_queue.push(Path(next_path.node_ptr->shortest, next_path.node_ptr));
        }
        if(path.dist + next_path.dist == next_path.node_ptr->shortest)
        {
            next_path.node_ptr->prev.push_back(path.node_ptr);
        }
    }
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cerr << "Input file path argument is missing" << std::endl;
        exit(1);
    }

    std::ifstream input;
    input.open(argv[1]);
    
    if(input.fail())
    {
        std::cerr << "Something went wrong while opening the file" << std::endl;
        exit(1);
    }
    
    size_t node_num, edge_num;
    input >> node_num >> edge_num;
    
    std::vector<Node> nodes(node_num);
    for(size_t i = 0; i < node_num; ++i)
    {
        nodes[i].index = i;
    }

    for(size_t i = 0; i < edge_num; ++i)
    {
        size_t first_node, second_node, distance;
        input >> first_node >> second_node >> distance;
        nodes[first_node].edges.push_back(Path(distance, &nodes[second_node]));
        nodes[second_node].edges.push_back(Path(distance, &nodes[first_node]));
    }

    size_t begin, end;
    input >> begin >> end;

    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> update_queue;
    nodes[begin].shortest = 0;
    update_queue.push(Path(0, &nodes[begin]));
    while(!update_queue.empty())
    {
        dijkstra(update_queue);
    }

    std::cout << "Shortest distance: " << nodes[end].shortest << std::endl;
    
    std::vector<size_t> path;
    std::vector<std::string> output;
    print_paths(&nodes[begin], &nodes[end], path, output);
    
    std::sort(output.begin(), output.end());
    for(size_t i = 0; i < output.size(); ++i)
    {
        std::cout << output[i] << std::endl;
    }

    input.close();
    return 0;
}