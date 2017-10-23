#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// find all occurences of str, in stc and replace with rep
void find_replace(char *text, char *out, char *find, char *replace)
{
	char *p = strstr(text, find); // get pointer to find in text
    do {   
        if(p) { // if p doesn't point to null
            char buf[1000]; // temporary string
            memset(buf,'\0',strlen(buf)); // add null terminator to buffer
            strncpy(buf,text,strlen(text) - strlen(p)); // copy the text before the find to buffer
            strcat(buf,replace); // concat the replace to buffer
            strcat(buf,p+strlen(find)); // contact the rest of the string to buffer

            memset(text,'\0',strlen(text)); // add null terminator to modified text
            strcpy(out,buf); // copy buffer to output string
        }   

    } while(p && (p = strstr(text, find))); // loop as long as p exists in text
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

	char text[1500]; // single array to hold entire paragraph
	int cc = 0; // tracks how many words are read
	int swaps = 9; // how many words to swap

	// array of words to find
	char find[9][50] = {
		"Inferno",
		"In dark woods",
		"those woods",
		"to enter",
		"crest",
		"Below a hill",
		"shoulders",
		"planet",
		"dante",
	};

	// array of words to replace
	char replace[9][50] = {
		"Paradisio",
		"using Windows 8.1",
		"Windows 8.1",
		"to use 8.1",
		"screen",
		"Before a monitor",
		"GUI",
		"UNIX",
		"Shakespeare",
	};
	
	// read char from file until EOF
	while ((text[cc] = getc(f)) != EOF)
		cc++; // increment counter
	
	char out[1500]; // to store output text
	int i; // sentinal for loop
	for (i = 0; i < swaps; i++) {
		// use find and replace
		find_replace(text, out, find[i], replace[i]);
	}

	// write new characters to file
	for (i=0; i<cc; i++)
		fputc(out[i], f2);
	
	// close the file streams
	fclose(f);
	fclose(f2);
}
