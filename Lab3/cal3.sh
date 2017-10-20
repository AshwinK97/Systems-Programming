#!/bin/bash

if [[ "$#" -eq 0 ]]; then                          # if no arguments are given
	echo "you must provide at least one month"
else                                               # if atleast one argument is given
	cal ${1} $(date +"%Y")                         # print the specified month
	if [[ "$#" -eq 2 ]]; then                      # if two arguments are given
		echo "$2 is not a valid month/input"
	fi
fi
