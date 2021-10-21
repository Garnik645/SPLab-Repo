#!/bin/bash
SCRIPT_PATH="../Scripts/num_rev.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

test_case() {
 if [ "$1" != "$2" ]
 then
  echo "fail"
  exit 1
 fi
}

test_case "$("$REAL_PATH" 123)" "321"
test_case "$("$REAL_PATH" 439)" "934"
test_case "$("$REAL_PATH" 125346)" "643521"

echo "succes"
