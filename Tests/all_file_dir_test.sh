#!/bin/bash
SCRIPT_PATH="../Scripts/all_file_dir.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

test_case() {
 if [ "$1" != "$2" ]
 then
  echo "fail"
  exit 1
 fi
}

test_case "$("$REAL_PATH" "$THIS_PATH/..")" "/home/garnik-kh/git_workspace/SPLab-Repo:
CMake
README.md
Scripts
Tests

/home/garnik-kh/git_workspace/SPLab-Repo/CMake:
CMakeLists.txt
main.cpp
MathFunctionLib

/home/garnik-kh/git_workspace/SPLab-Repo/CMake/MathFunctionLib:
CMakeLists.txt
gcd.cpp
gcd.h

/home/garnik-kh/git_workspace/SPLab-Repo/Scripts:
all_file_dir.sh
file_type.sh
line_count.sh
num_rev.sh

/home/garnik-kh/git_workspace/SPLab-Repo/Tests:
all_file_dir_test.sh
file_type_test.sh
line_count_test.sh
num_rev_test.sh"

test_case "$("$REAL_PATH" "$THIS_PATH")" "/home/garnik-kh/git_workspace/SPLab-Repo/Tests:
all_file_dir_test.sh
file_type_test.sh
line_count_test.sh
num_rev_test.sh"

echo "succes"
