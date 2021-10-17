#!/bin/bash
# Counts lines in the given argument
# Garnik Khroyan 9/10/2021

if [ $# != 1 ]
then
	echo 'Usage: Wrong amount of arguments'
	exit 1
fi

if [ ! -f $1 ]
then
	echo 'File doesnt exist or its not possible to read from it'
	exit 1
fi

cat $1 | wc -l
