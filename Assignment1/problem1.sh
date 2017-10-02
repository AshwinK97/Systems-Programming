#!/bin/bash

# get the string from the user
echo "Enter a string"
read haystack

# get the substring from user
echo "Enter a substring"
read needle

# use regex to get all occurences of the substring
# pipe them to wc and count each line
count=$(grep -o "$needle" <<< "$haystack" | wc -l)

# output the information
echo "occurences of '$needle' in '$haystack' = $count"
