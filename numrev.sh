#!/bin/bash
# Prints number in reverse order
# Garnik Khroyan 9/10/2021

if [ $# != 1 ]
then
	echo 'Usage: One numeric argument to reverse'
	exit
fi

echo $1 | rev

