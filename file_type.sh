#!/bin/bash
# Reports file type
# Garnik Khroyan 9/10/2021

if [ $# != 1 ]
then
 echo 'Usage: A single argument which is a path'
 exit 1

elif [ -d $1 ]
then
 echo 'It is a directory'

elif [ -f $1 ]
then
 echo 'It is a regular file'

elif [ ! -e $1 ]
then
 echo 'Path doesnt exist'
	exit 1
fi
