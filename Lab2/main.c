#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// find and replace a character within a string
char* find_replace(char* word, char find, char replace){
	char *current_pos = strchr(word, find); // get pointer to first occurance of find
	// loop as long as current positon is valid
	while (current_pos) {
		*current_pos = replace; // swap occurence of find with replace
		current_pos = strchr(current_pos,find); // get next occurence of find
	}
	return word;
}

int main(int argc, char *argv[]) {
	FILE *f; // pointer for input file
	FILE *f2; // pointer for output file

	// open input.txt and check if it is readable
	if ((f=fopen("Input.txt", "r")) == NULL) {
		printf("Unable to open 'Input.txt' for reading\n");
		exit(0);
	}
	
	// open Heaven.txt and check if it is writable
	if ((f2=fopen("Heaven.txt", "w")) == NULL) {
		printf("Unable to open 'Heaven.txt' for writing\n");
		exit(0);
	}

	// array of 150 words 20 characters each
	char words[150][20];
	// track how many words are read
	int wc = 0;

	while (1) {
		// read word from file into word array
		if (fscanf(f, "%s", words[wc]) != 1)
			break; // if we could not read a string, break
		
		// check if 'a' is in current word
		if (strchr(words[wc], 'a') > 0)
			// find all 'a' and replace with 'b', and store in array
			strcpy(words[wc], find_replace(words[wc], 'a', 'b'));
		
		fputs(words[wc], f2); // write word to file
		fputs("\n", f2); // write newline to file

		wc++; // increment counter
	}
	
	// close the file streams
	fclose(f);
	fclose(f2);
}
