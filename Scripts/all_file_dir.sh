#!/bin/bash
# Prints all file names on given folder with subfolders
# Garnik Khroyan 9/10/2021

if [ $# != 1 ]
then
 echo "Usage: Give a folder name to see all file names on given folder with subfolders"
 exit 1

elif [ -d $1 ]
then
 ls -R $1
else
 echo "Given file is not a folder"
 exit 1
fi
