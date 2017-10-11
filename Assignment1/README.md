# SOFE3200 - Assignment 1
Name: **Ashwin Kamalakannan**  
ID  : **100584423**  

These scripts use the bash interperator located in /bin/bash
#### To run each script:
1. download files and change to the containing directory
2. type `chmod u+x problem1.sh problem2.sh problem3.sh`
3. type `./[script].sh` where `[script]` is the name of the script you want to run  

## problem1.sh

For problem 1, we have to find the number of occurences of a substring in the main string.  

#### Process
1. ask the user to enter string for the haystack
2. ask the user to enter string for the needle
3. use grep to get occurences of 'needle' in 'haystack'
4. pipe grep output to wc and specify to count lines only
5. output the number of occurences


## problem2.sh

For problem 2, we have to wait 5 seconds and then write the current time to 'sampling.txt' continuously until system interrupt.  

#### Process
1. start an infinite loop
2. use date command to get the date, formatted for just the 12 hour time
3. append (>>) this to sampling.txt
4. use sleep to wait 5 seconds

## problem3.sh

For problem 3, we have to make a multiple choice consisting of 5 questions with 2 possible answers for each.  
For the mail functionality to work, you have to install GNU mailuitls

#### Process
1. store all of the question in an array
2. store all of the correct answers in an array
3. initialize score and loop counter to 0
4. iterate through each question in array, print each question
5. prompt the user for their answer, check if the answer matches answer array
6. increment score for correct answers
7. output the score to the screen
8. mail the score to root
