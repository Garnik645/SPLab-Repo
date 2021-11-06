#!/bin/bash
DIV=$(dirname $(readlink -f $0))
run_program() {
    ${DIV}/find_path $1
}
g++ find_path.cpp -o find_path
for i in {1..2}
do
    touch tester.txt
    run_program "${DIV}/Tests/test${i}.in.txt" > tester.txt
    if ! cmp -s "${DIV}/tester.txt" "${DIV}/Tests/test${i}.out.txt"
    then
        echo "fail"
        exit 1
    fi
    rm tester.txt
done
rm find_path
echo "success"