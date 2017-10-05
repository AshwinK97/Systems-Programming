#!/bin/bash

gcc CAPFIX_mod.c -o capfix
gcc ARGS.c -o args
./capfix Names.txt
