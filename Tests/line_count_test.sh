#!/bin/bash
SCRIPT_PATH="../Scripts/line_count.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

OUT=$("$REAL_PATH" "$THIS_PATH"/../Scripts/num_rev.sh)
if [ "$OUT" != 11 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" "$THIS_PATH"/../Scripts/all_file_dir.sh)
if [ "$OUT" != 16 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" "$THIS_PATH"/../Scripts/file_type.sh)
if [ "$OUT" != 22 ]
then
 echo "fail"
 exit 1
fi

echo "succes"
