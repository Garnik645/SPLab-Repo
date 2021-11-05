#!/usr/bin/env bash

DIV=$(dirname $(readlink -f $0))
run_script() {
 bash ${DIV}/../Scripts/$1 $2
}

run_script "all_file_dir.sh" "/usr/src/"

run_script "file_type.sh" "${DIV}/../Scripts/file_type.sh"

run_script "line_count.sh" "${DIV}/../Scripts/line_count.sh"

run_script "num_rev.sh" "1234"
