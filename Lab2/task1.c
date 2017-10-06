#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *f; // pointer for input file
	FILE *f2; // pointer for output file	

	// open Input.txt and check if it is readable
	if ((f=fopen("Input.txt", "r")) == NULL) {
		printf("Unable to open 'Input.txt' for reading\n");
		exit(0);
	}
	
	// open Heaven.txt and check if it is writable
	if ((f2=fopen("Heaven.txt", "w")) == NULL) {
		printf("Unable to open 'Heaven.txt' for writing\n");
		exit(0);
	}

	// array to hold entire paragraph
	char text[1000];

	// track how many charcters are read
	int cc = 0;
	
	// read char from input file until EOF
	while ((text[cc] = getc(f)) != EOF) {
		if (text[cc] == 'a') // if current char is 'a', replace with 'b'
			text[cc] = 'b';
		fputc(text[cc], f2); // write character to output file
		cc++; // increment counter
	}
	
	// close the file streams
	fclose(f);
	fclose(f2);
}
