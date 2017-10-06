#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* find_replace(char* word, char find, char replace){
	char *current_pos = strchr(word, find);
	while (current_pos){
		*current_pos = replace;
		current_pos = strchr(current_pos,find);
	}
	return word;
}

int main(int argc, char *argv[]) {
	FILE *f; // pointer for input file
	//FILE *f2; // pointer for output file

	// open input.txt and check if it is readable
	if ((f=fopen("Input.txt", "r")) == NULL) {
		printf("Unable to open 'Input.txt' for reading\n");
		exit(0);
	}
	
	// open Heaven.txt and check if it is writable
	//if ((f=fopen("Heaven.txt", "w")) == NULL) {
	//	printf("Unable to open 'Heaven.txt' for writing\n");
	//	exit(0);
	//}

	// array of words, 150 words 20 characters each
	char words[500][500];
	// track how many words are read
	int wc = 0;

	while (1) {
		if (fscanf(f, "%s", words[wc]) != 1)
			break;
		
		if (strchr(words[wc], 'a') > 0) {
			strcmp(words[wc], find_replace(words[wc], 'a', 'b'));
			printf("%s\n", words[wc]);
		}
		wc++;
	}

	// print words out
	//int i;
	//for (i=0; i<wc; i++)
	//	printf("%s\n", words[i]);
	
	// close the file streams
	fclose(f);
	//fclose(f2);
}
