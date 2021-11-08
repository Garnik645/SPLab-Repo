#!/bin/bash
DIV=$(dirname $(readlink -f $0))
EXE=${DIV}/build/find_path

if [ ! -f "${EXE}" ]
then
    echo "Executable file doesn't exist!"
    exit 1
fi

run_program() {
    ${EXE} $1
}

for i in {1..2}
do
    touch ${DIV}/tester.txt
    run_program "${DIV}/Tests/test${i}.in.txt" > "${DIV}/tester.txt"
    if ! cmp -s "${DIV}/tester.txt" "${DIV}/Tests/test${i}.out.txt"
    then
        echo "fail"
        rm ${DIV}/tester.txt
        exit 1
    fi
    rm ${DIV}/tester.txt
done

echo "success"