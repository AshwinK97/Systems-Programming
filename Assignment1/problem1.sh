#!/bin/bash

echo "Enter a string"
read haystack
echo "Enter a substring"
read needle
count=$(grep -o "$needle" <<< "$haystack" | wc -l)
echo "occurences of '$needle' in '$haystack' = $count"
