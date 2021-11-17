#!/bin/bash
DIV=$(dirname $(readlink -f $0))
EXE=${DIV}/build/find_path
GEN_1=${DIV}/Generated_Tests/gen_1
GEN_2=${DIV}/Generated_Tests/gen_2

run_program() {
    ${EXE} $1
}

if [ ! -f "${EXE}" ]
then
    echo "Executable file doesn't exist!"
    exit 1
fi

if [ ! -f "${GEN_1}" ]
then
    echo "Test Generator 1 doesn't exist!"
    exit 1
fi

if [ ! -f "${GEN_2}" ]
then
    echo "Test Generator 2 doesn't exist!"
    exit 1
fi

# Test 1
run_program "${DIV}/Tests/test1.in.txt" > "${DIV}/tester.txt"
if ! cmp -s ${DIV}/tester.txt ${DIV}/Tests/test1.out.txt
then
    echo "test 1: fail"
    exit 1
else
    echo "test 1: pass"
fi
rm ${DIV}/tester.txt

# Test 2
for i in {1..100}
do
    ${GEN_1} ${DIV}/Generated_Tests
    run_program "${DIV}/Generated_Tests/gen_test_1.in.txt" > "${DIV}/tester.txt"
    if ! cmp -s ${DIV}/tester.txt ${DIV}/Generated_Tests/gen_test_1.out.txt
    then
        echo "test 2.${i}: fail"
        exit 1
    else
        echo "test 2.${i}: pass"
    fi
    rm ${DIV}/tester.txt
done
rm ${DIV}/Generated_Tests/gen_test_1.in.txt ${DIV}/Generated_Tests/gen_test_1.out.txt

# Test 3
for i in {1..50}
do
    ${GEN_2} ${DIV}/Generated_Tests
    run_program "${DIV}/Generated_Tests/gen_test_2.in.txt" > "${DIV}/tester.txt"
    if ! cmp -s ${DIV}/tester.txt ${DIV}/Generated_Tests/gen_test_2.out.txt
    then
        echo "test 3.${i}: fail"
        exit 1
    else
        echo "test 3.${i}: pass"
    fi
    rm ${DIV}/tester.txt
done
rm ${DIV}/Generated_Tests/gen_test_2.in.txt ${DIV}/Generated_Tests/gen_test_2.out.txt

echo "success"