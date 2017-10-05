#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *f;
	f = fopen("Input.txt", "r");
	char words[100][20];
	
	// read words into words array
	int wc = 0;
	while (1) {
		if (fscanf(f, "%s", words[wc]) != 1)
			break;
		wc++;
		if (words[wc] =) {
			printf("found Systems\n");
			if (fscanf(f, "%s", words[wc]) != 1)
				break;
			if (words[wc] == "Programming") {
				words[wc][5] = 'a';
				printf("%s\n", words[wc]);
			}
			wc++;
		}
		else
			wc++;
	}

	int i;
	for (i=0; i<wc; i++)
		printf("%s\n", words[i]);
}
