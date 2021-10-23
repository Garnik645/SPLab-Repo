#!/bin/bash
SCRIPT_PATH="../Scripts/line_count.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

test_case() {
 if [ "$1" != "$2" ]
 then
  echo "fail"
  exit 1
 fi
}

test_case "$("$REAL_PATH" "$THIS_PATH"/../Scripts/num_rev.sh)" "11"
test_case "$("$REAL_PATH" "$THIS_PATH"/../Scripts/all_file_dir.sh)" "16"
test_case "$("$REAL_PATH" "$THIS_PATH"/../Scripts/file_type.sh)" "22"

echo "succes"
