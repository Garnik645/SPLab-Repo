#!/bin/bash
DIV=$(dirname $(readlink -f $0))
run_program() {
    ${DIV}/find_path $1
}
g++ ${DIV}/find_path.cpp -o ${DIV}/find_path
for i in {1..2}
do
    touch ${DIV}/tester.txt
    run_program "${DIV}/Tests/test${i}.in.txt" > "${DIV}/tester.txt"
    if ! cmp -s "${DIV}/tester.txt" "${DIV}/Tests/test${i}.out.txt"
    then
        echo "fail"
        rm ${DIV}/tester.txt
        rm ${DIV}/find_path
        exit 1
    fi
    rm ${DIV}/tester.txt
done
rm ${DIV}/find_path
echo "success"