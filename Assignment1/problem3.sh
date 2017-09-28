#!/bin/bash

qlist=("question1" "question2" "question3" "question4" "question5")
alist=("answer1" "answer2" "answer3" "answer4" "answer5")
score=0

i=0
for q in ${qlist[@]}
do
	echo ${q}
	read answer
	
	if [$answer = ${alist[i]}] 
	then
		echo "correct answer"
	fi
	$i+=1
done
