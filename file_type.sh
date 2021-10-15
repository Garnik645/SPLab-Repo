#!/bin/bash
# Reports file type
# Garnik Khroyan 9/10/2021

if [ $# != 1 ]
then
	echo 'Usage: A single argument which is a path'
	exit
fi

if [ -d $1 ]
then
	echo 'It is a directory'
fi

if [ -f $1 ]
then
	echo 'It is a regular file'
fi

if [ ! -e $1 ]
then
	echo 'Path doesnt exist'
fi
