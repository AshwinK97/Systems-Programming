#!/bin/bash

# infinite loop
while true
do
	# get the formatted date and output to file
	date +%r >> sampling.txt

	# wait for 5 seconds
	sleep 5 
done
