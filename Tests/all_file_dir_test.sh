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

TEST_PATH="$(realpath "$THIS_PATH/..")"

test_case "$("$REAL_PATH" "$THIS_PATH/..")" "${TEST_PATH}:
CMake
README.md
Scripts
Tests

${TEST_PATH}/CMake:
CMakeLists.txt
main.cpp
MathFunctionLib

${TEST_PATH}/CMake/MathFunctionLib:
CMakeLists.txt
gcd.cpp
gcd.h

${TEST_PATH}/Scripts:
all_file_dir.sh
file_type.sh
line_count.sh
num_rev.sh

${TEST_PATH}/Tests:
all_file_dir_test.sh
file_type_test.sh
line_count_test.sh
num_rev_test.sh"

TEST_PATH="$(realpath "$THIS_PATH")"

test_case "$("$REAL_PATH" "$THIS_PATH")" "${TEST_PATH}:
all_file_dir_test.sh
file_type_test.sh
line_count_test.sh
num_rev_test.sh"

echo "succes"
