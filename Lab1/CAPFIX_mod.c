#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reads input file and returs number of lines read
void ReadData(FILE *fpt, char first[20][30], char last[20][30]) {
	
	// terminate if the wrong number of arguments is given
	if (argc != 2) {
		printf("Usage: CAPFIX [filename]\n");
		exit(0);
	}
	
	// terminate if the file at the given path can not be read
	if ((fpt = fopen(argv[1], "r")) == NULL) {
		printf("Unable to open %s for reading\n", argv[1]);
		exit(0);
	}
	
	int line = 0;
	// loop through each line of file until we can't read 2 items from a line
	while(1) {
		// look for 2 space seperated strings in each line
		// write the strings to the last and first arrays
		// index using total, increment total after successful read
		if (fscanf(fpt, "%s %s", last[total], first[total]) != 2)
			break;
		count++;
	}
	
	// close the file object
	fclose(fpt);
}

// capitalizes the first character in each name
// lowercases the rest of the characters in each name
void CapFix(char word[30]) {

	// i is used to index which word we are currently on
	// j is used to index which character of the current word are we on
	// total is the length of the word array
	int i, j, total sizeof(word)/sizeof(word[0]);
	
	// iterate through each word in the array
	for (i=0; i<total; i++) {
		// check if the first character of each word is a valid lower case letter
		// if it is, remove the lower case char and replace it with the equivilent capital one
		if (word[i][0] >= 'a' && word[i][0] <= 'z)
			word[i][0] = word[i][0] - 'a' + 'A';
		
		// iterate through the rest of the letters in the word
		for (j = 1; j < strlen(word[i]); j++) {
			// check if the character is a valid upper case letter
			// if it is, remove the upper case char and replace it with the equivilent capital one
			if (word[i][j] >= 'A' && word[i][j] <= 'Z')
				word[i][j] = word[i][j] - 'A' + 'a';
		}
	}
}

int main(int argc, char *argv[]) {
	
	FILE *fpt;
	char first[20][30],last[20][30];
	
	// populates the first and last arrays, gets the total
	ReadData(fpt, first, last);

	// fixes capitalization in first array
	CapFix(first);

	// fixes capitalization in second array
	CapFix(last);
	
	// prints the contents of first and last, side by side
	for (i=0; i<total; i++)
		printf("%s %s\n",first[i],last[i]);
}
