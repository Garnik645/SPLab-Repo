#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
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

    // pointer to end of the path
    Node* node_ptr;

    Path(int x = 0, Node* ptr = nullptr) : dist(x), node_ptr(ptr) {} 
    
    friend bool operator>(const Path& lhs, const Path& rhs)
    {
        return lhs.dist > rhs.dist;
    }
};

// print all shortest paths
void print_paths(Node* start, Node* current, std::vector<size_t>& path, std::vector<std::string>& sorted)
{
    // if the beginning is reached, save the path into the vector 
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
    // recursivly go throw the path from end to start
    for(size_t i = 0; i < current->prev.size(); ++i)
    {
        path.push_back(current->index);
        print_paths(start, current->prev[i], path, sorted);
        path.pop_back();
    }
}

// Dijkstra's algorithm
void dijkstra(std::priority_queue<Path, std::vector<Path>, std::greater<Path>>& que)
{
    Path path = que.top();
    que.pop();
    // go through all neighbour nodes
    for(size_t i = 0; i < path.node_ptr->edges.size(); ++i)
    {
        Path next_path = path.node_ptr->edges[i];
        // check if shortest path can be updated
        if(path.node_ptr->shortest + next_path.dist < next_path.node_ptr->shortest)
        {
            next_path.node_ptr->shortest = path.node_ptr->shortest + next_path.dist;
            next_path.node_ptr->prev.clear();
            que.push(Path(next_path.node_ptr->shortest, next_path.node_ptr));
        }
        // add current node into the vector of previously visited nodes with the shortest distance
        if(path.dist + next_path.dist == next_path.node_ptr->shortest)
        {
            next_path.node_ptr->prev.push_back(path.node_ptr);
        }
    }
}

int main(int argc, char** argv)
{
    // check if input file is given
    if(argc < 2)
    {
        std::cerr << "Input file path argument is missing\n";
        exit(1);
    }

    // open input file
    std::ifstream input;
    input.open(argv[1]);
    
    // check for errors while opening the file
    if(input.fail())
    {
        std::cerr << "Something went wrong while opening the file\n";
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

    // Dijkstra's algorithm
    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> que;
    v[begin].shortest = 0;
    que.push(Path(0, &v[begin]));
    while(!que.empty())
    {
        dijkstra(que);
    }

    // print shortest distance
    std::cout << "Shortest distance: " << v[end].shortest << std::endl;
    
    // get all shortest paths
    std::vector<size_t> path;
    std::vector<std::string> sorted;
    print_paths(&v[begin], &v[end], path, sorted);
    
    // sort all the paths and print in lexicographical order
    std::sort(sorted.begin(), sorted.end());
    for(size_t i = 0; i < sorted.size(); ++i)
    {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}