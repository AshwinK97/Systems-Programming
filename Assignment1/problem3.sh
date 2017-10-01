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

for q in ${qlist[@]}
do
	printf "${q//_/ }"
	read answer
	
	if [ $answer = "${alist[i]}" ]
	then                                         
		score=$(($score + 1))
	fi

	i=$(($i + 1))
	printf "\n"
done

printf "Test score mailed to root\n"

mail -s "Score from 'problem3.sh'" "root"  <<EOF
Your score was: $score
EOF
