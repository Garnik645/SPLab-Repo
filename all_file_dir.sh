#!/bin/bash
# Print all file names on given folder with subfolders
# Garnik Khroyan 9/10/2021

if [ -d $1 ]
then
	ls -R $1
fi
