#!/bin/bash

gcc CAPFIX.c -o capfix
gcc ARGS.c -o args
./capfix Names.txt
