#!/bin/bash
SCRIPT_PATH="../Scripts/file_type.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

test_case() {
 if [ "$1" != "$2" ]
 then
  echo "fail"
  exit 1
 fi
}

test_case "$("$REAL_PATH" "$REAL_PATH")" "It is a regular file"
test_case "$("$REAL_PATH" "$THIS_PATH")" "It is a directory"

echo "succes"
