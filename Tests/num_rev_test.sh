#!/bin/bash
SCRIPT_PATH="../Scripts/num_rev.sh"
THIS_PATH=$(dirname "$0")
REAL_PATH=$THIS_PATH/$SCRIPT_PATH

OUT=$("$REAL_PATH" 123)
if [ "$OUT" != 321 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" 934)
if [ "$OUT" != 439 ]
then
 echo "fail"
 exit 1
fi

OUT=$("$REAL_PATH" 125346)
if [ "$OUT" != 643521 ]
then
 echo "fail"
 exit 1
fi

echo "succes"
