#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// find and replace a character within a string
char* find_replace(char* word, char* find, char* replace){
	char *current_pos = strstr(word, find); // get pointer to first occurance of find
	// loop as long as current positon is valid
	while (current_pos) {
		*current_pos = replace; // swap occurence of find with replace
		current_pos = strstr(current_pos,find); // get next occurence of find
	}
	return word;
}

int main(int argc, char *argv[]) {
	FILE *f; // pointer for input file
	FILE *f2; // pointer for output file
	
	// open Input.txt and check if it is readable
	if ((f=fopen("Input.txt", "r")) == NULL) {
		printf("Unable to open 'Input.txt' for reading\n");
		exit(0);
	}
	
	// open Dante.txt and check if it is writable
	if ((f2=fopen("Dante.txt", "w")) == NULL) {
		printf("Unable to open 'Dante.txt' for writing\n");
		exit(0);
	}

	// single array to hold entire paragraph
	char text[1000];

	// track how many charcters are read
	int cc = 0;
	
	// read char from file until EOF
	while ((text[cc] = getc(f)) != EOF)
		cc++; // increment counter
	
	// use find and replace to replace all 'a' with 'b'
	strcpy(text, find_replace(text, "The", "AAA"));

	int i;
	for (i=0; i<cc; i++)
		fputc(text[i], f2);
	
	// close the file streams
	fclose(f);
	fclose(f2);
}
