#!/bin/bash

# array of questions
qlist=("What_is_1+1?\na)_2____b)_3\n>>_" 
	   "what_is_the_tallest_mountain?\na)_Mt_Saint_Hellens____b)_Mt_Everest\n>>_" 
	   "What_is_the_best_operating_system?\na)_Ubuntu_17.04____b)_Windows_10\n>>_" 
	   "What_is_the_best_scripting_language?\na)_Bash_script____b)_Batch_script\n>>_" 
	   "Who_is_the_best_professor?\na)_Akramul_Azim____b)_Koro_Sensei\n>>_")

# array of answers
alist=("a" "b" "a" "a" "b")

score=0 # store the score
i=0     # counter for loop

# iterate through each question
for q in ${qlist[@]}
do
	# print the current quetsion
	printf "${q//_/ }"

	# get an answoer fromm the user
	read answer
	
	# check if answer matches
	if [ $answer = "${alist[i]}" ]
	then                                         
		score=$(($score + 1)) # increment user score
	fi

	i=$(($i + 1)) # increment loop counter
	printf "\n"
done

# print the score and email message
printf "You scored $score points\n"
printf "Your score has been emailed to you\n"

# use GNU mailutils to email the score to root
mail -s "Score from 'problem3.sh'" "root"  <<EOF
Your score was: $score
EOF