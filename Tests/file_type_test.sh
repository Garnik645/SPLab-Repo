#!/bin/bash
SCRIPT_PATH="../file_type.sh"
THIS_PATH=$(pwd)
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

OUT=$("$REAL_PATH" "$REAL_PATH")
if [ "$OUT" != "It is a regular file" ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" "$THIS_PATH")
if [ "$OUT" != "It is a directory" ]
then
 echo "fail"
 exit 1
fi

echo "succes"
