#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fpt;
	char first[20][30],last[20][30];
	int i,j,total;

	if (argc != 2) {
		printf("Usage: CAPFIX [filename]\n");
		exit(0);
	}

	if ((fpt=fopen(argv[1],"r")) == NULL) {
		printf("Unable to open %s for reading\n",argv[1]);
		exit(0);
	}

	total=0;

	while (1) {
		if (fscanf(fpt,"%s %s",last[total],first[total]) != 2)
			break;
		total++;
	}

	for (i=0; i<total; i++) {
		if (first[i][0] >= 'a' && first[i][0] <= 'z')
			first[i][0]=first[i][0]-'a'+'A';

		for (j=1; j<strlen(first[i]); j++)
			if (first[i][j] >= 'A' && first[i][j] <= 'Z')
				first[i][j]=first[i][j]-'A'+'a';
	}

	for (i=0; i<total; i++) {
		if (last[i][0] >= 'a' && last[i][0] <= 'z')
			last[i][0]=last[i][0]-'a'+'A';

		for (j=1; j<strlen(last[i]); j++)
			if (last[i][j] >= 'A' && last[i][j] <= 'Z')
				last[i][j]=last[i][j]-'A'+'a';
	}

	for (i=0; i<total; i++)
		printf("%s %s\n",first[i],last[i]);

	fclose(fpt);
}