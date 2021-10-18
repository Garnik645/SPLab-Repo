#!/bin/bash
SCRIPT_PATH="../line_count.sh"
THIS_PATH=$(pwd)
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

OUT=$("$REAL_PATH" "$THIS_PATH"/../num_rev.sh)
if [ "$OUT" != 11 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" "$THIS_PATH"/../all_file_dir.sh)
if [ "$OUT" != 16 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" "$THIS_PATH"/../file_type.sh)
if [ "$OUT" != 22 ]
then
 echo "fail"
 exit 1
fi

echo "succes"
