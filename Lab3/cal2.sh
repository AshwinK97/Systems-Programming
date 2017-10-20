#!/bin/bash

if [[ "$#" -eq 0 ]]; then      # if no arguments are given
	cal
elif [[ "$#" -eq 1 ]]; then    # if only month is given
	cal ${1} $(date +"%Y")
else                           # if both month and year are given
	cal ${1} ${2}
fi
