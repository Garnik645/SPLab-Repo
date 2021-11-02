#!/usr/bin/env bash

find_path() {
 RETVAL=$(find / -iname "$1" -print 2>/dev/null)
}

run_script() {
 bash "$(find / -iname "$1" -print 2>/dev/null)" "$2"
}

run_script "all_file_dir.sh" "/usr/src"

find_path "file_type.sh"
run_script "file_type.sh" ${RETVAL}

find_path "line_count.sh"
run_script "line_count.sh" ${RETVAL}

run_script "num_rev.sh" "1234"
