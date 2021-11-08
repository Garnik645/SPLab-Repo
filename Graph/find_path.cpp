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

void print_paths(Node* start, Node* current, std::vector<size_t>& path, std::vector<std::string>& sorted)
{
    if(current == start)
    {
        std::string str = "";
        str += std::to_string(start->index) + ' ';
        for(int i = path.size() - 1; i >= 0; --i)
        {
            str += std::to_string(path[i]) + ' ';
        }
        sorted.push_back(str);
        return;
    }
    for(size_t i = 0; i < current->prev.size(); ++i)
    {
        path.push_back(current->index);
        print_paths(start, current->prev[i], path, sorted);
        path.pop_back();
    }
}

void dijkstra(std::priority_queue<Path, std::vector<Path>, std::greater<Path>>& que)
{
    Path path = que.top();
    que.pop();
    for(size_t i = 0; i < path.node_ptr->edges.size(); ++i)
    {
        Path next_path = path.node_ptr->edges[i];
        if(path.node_ptr->shortest + next_path.dist < next_path.node_ptr->shortest)
        {
            next_path.node_ptr->shortest = path.node_ptr->shortest + next_path.dist;
            next_path.node_ptr->prev.clear();
            que.push(Path(next_path.node_ptr->shortest, next_path.node_ptr));
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
        std::cerr << "Input file path argument is missing\n";
        exit(1);
    }

    std::ifstream input;
    input.open(argv[1]);
    
    if(input.fail())
    {
        std::cerr << "Something went wrong while opening the file\n";
        exit(1);
    }
    
    size_t n, m;
    input >> n >> m;
    
    std::vector<Node> v(n);
    for(size_t i = 0; i < n; ++i) v[i].index = i;

    for(size_t i = 0; i < m; ++i)
    {
        size_t x, y, z;
        input >> x >> y >> z;
        v[x].edges.push_back(Path(z, &v[y]));
        v[y].edges.push_back(Path(z, &v[x]));
    }

    size_t begin, end;
    input >> begin >> end;

    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> que;
    v[begin].shortest = 0;
    que.push(Path(0, &v[begin]));
    while(!que.empty())
    {
        dijkstra(que);
    }

    std::cout << "Shortest distance: " << v[end].shortest << std::endl;
    
    std::vector<size_t> path;
    std::vector<std::string> sorted;
    print_paths(&v[begin], &v[end], path, sorted);
    
    std::sort(sorted.begin(), sorted.end());
    for(size_t i = 0; i < sorted.size(); ++i)
    {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}