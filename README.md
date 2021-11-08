# SPLab lessons
## Shell scripts and cmake task
### It contains shell scripts, tests for that scripts, cmake files.<br />
<br />

1. Give all_file_dir.sh path to the directory and it will print all file names on given folder with subfolders.
2. Give file_type.sh path to the file and it will report its type.
3. Give line_count.sh path to the file which is possible to read and it will report number of lines in the given argument.
4. Give num_rev.sh a number and it will print it in reverse order.
<br />
<br />

## Docker task
### Task to create a Docker image which runs all the scripts with specific arguments.<br />
<br />

To create a docker image you should run this shell command from the SPLab-Repo folder:
```
docker build -t splab -f Docker/Dockerfile .
```
Then you should be able to run the image:
```
docker run --rm splab
```
<br />
<br />

## Graph algorithm task
### Task to find all the shortest paths between two nodes in an undirected graph.<br />
<br />
Task folder contains find_path.cpp program which reads from the input file,
uses Dijkstra's algorithm to find shortest path between the nodes,
and prints shortest distance and all the shortest paths in lexicographical order.
It also contains cmake files, tests and a shell script to run these tests.<br />

#### How to build
To build the project open the terminal in SPLab-Repo/Graph folder and run these two commands:
```
cmake -S . -B build/
make -C build/
```
<br />

#### Input file structure
The first line of input file contains two non-negative integers **N** & **M** (1 ≤ **N** ≤ 10<sup>4</sup>)
— the number of nodes and number of edges in a graph.<br />
Next **M** lines contain 3 non-negative integers **X**, **Y** & **Z** (0 ≤ **X**, **Y** < **N**).
**X** & **Y** — index of two nodes connected by an edge with the length of **Z**.<br />
Next line contains two non-negative integers **S** & **F** (0 ≤ **S**, **F** < **N**)
— index of the first node and the last node in a path.