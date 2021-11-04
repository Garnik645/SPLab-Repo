## SPLab lessons
It contains shell scripts, tests for that scripts, cmake files and Dockerfile.
1. Give all_file_dir.sh path to the directory and it will print all file names on given folder with subfolders
2. Give file_type.sh path to the file and it will report its type
3. Give line_count.sh path to the file which is possible to read and it will report number of lines in the given argument
4. Give num_rev.sh a number and it will print it in reverse order

Docker container runs all the scripts with specific arguments,
To create a docker image you should run this shell command from the SPLab-Repo folder:
```
docker build -t splab -f Docker/Dockerfile .
```
Than you should be able to run the image:
```
docker run --rm splab
```
