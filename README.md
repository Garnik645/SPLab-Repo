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
### Task to find all the shortest paths between two nodes in a graph.<br />
<br />
Task folder contains find_path.cpp program which reads from the input file,
uses Dijkstra's algorithm to find shortest path between the nodes,
and prints shortest distance and all the shortest paths in lexicographical order.
It also contains cmake files, tests and a shell script to run these tests.