#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// check if correct number and type of arguments were given
	if (argc != 2 || strlen(argv[1]) != 1) {
		printf("task2: incorrect arguments\n");
		printf("usage: %s <char>", argv[0]);
		exit(0);
	}
	
	FILE *f; // pointer for input file
	// open spam.txt and check if it is readable
	if ((f=fopen("spam.txt", "r")) == NULL) {
		printf("task2: unable to open 'Spam.txt' for reading\n");
		exit(0);
	}

	char c; // buffer to read characters
	int cc = 0; // initialize search character count
	
	// read characters until end of file
	while ((c = getc(f)) != EOF) {
		if (c == *argv[1]) // if search character is found, increment cc
			cc++;
	}

	printf("occurences of '%c': %d\n", *argv[1], cc); // output cc
	
	fclose(f); // close file stream
}
