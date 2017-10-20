#!/bin/bash

# if no arguments are given
if [[ "$#" -eq 0 ]]; then
	echo "you must provide at least one month"
else
	cal ${1} $(date +"%Y") # print the specified month
	# if two arguments are given
	if [[ "$#" -eq 2 ]]; then
		echo "$2 is not a valid month/input"
	fi
fi
