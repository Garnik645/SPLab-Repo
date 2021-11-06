#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <queue>

struct Path;
struct Node;

// structure representing nodes in graph
struct Node
{
    // node index
    size_t index;
    // edges of the node
    std::vector<Path> edges;
    // shortest path found from the beginning to this node
    int shortest = std::numeric_limits<int>::max();
    // previous nodes which came with the shortes path to this node
    std::vector<Node*> prev;
};

// structure representing paths and edges in graph
struct Path
{
    // distance of the path
    int dist;

    // pointer to end node of the path
    Node* node_ptr;

    Path(int x = 0, Node* ptr = nullptr) : dist(x), node_ptr(ptr) {} 
    
    friend bool operator>(const Path& lhs, const Path& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

// print all shortest paths
void print_paths(Node* start, Node* current, std::vector<size_t>& path)
{
    // print the path if reached the beginning
    if(current == start)
    {
        std::cout << start->index << ' ';
        for(int i = path.size() - 1; i >= 0; --i)
        {
            std::cout << path[i] << ' ';
        }
        std::cout << std::endl;
        return;
    }
    // recursively go through the path
    for(size_t i = 0; i < current->prev.size(); ++i)
    {
        path.push_back(current->index);
        print_paths(start, current->prev[i], path);
        path.pop_back();
    }
}

// Dijkstra's algorithm
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

int main()
{
    // open input file
    std::ifstream input;
    input.open("input.txt");
    
    // check for errors while opening the file
    if(input.fail())
    {
        std::cerr << "Error opening 'input.txt'\n";
        exit(1);
    }
    
    // get number of vertices and edges in graph
    size_t n, m;
    input >> n >> m;
    
    // create vertices
    std::vector<Node> v(n);
    for(size_t i = 0; i < n; ++i) v[i].index = i;

    // add edges
    for(size_t i = 0; i < m; ++i)
    {
        size_t x, y, z;
        input >> x >> y >> z;
        v[x].edges.push_back(Path(z, &v[y]));
        v[y].edges.push_back(Path(z, &v[x]));
    }

    // get the begin and end of the path
    size_t begin, end;
    input >> begin >> end;

    // Dijkstra
    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> que;
    v[begin].shortest = 0;
    que.push(Path(0, &v[begin]));
    while(!que.empty())
    {
        dijkstra(que);
    }

    // print results
    std::cout << "Shortest distance: " << v[end].shortest << std::endl;
    std::vector<size_t> p;
    print_paths(&v[begin], &v[end], p);
    
    return 0;
}