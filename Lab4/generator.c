#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int generate(FILE *f) {
	if (f == NULL) {
		return -1;
	}
	srand(time(NULL));
	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 1000; j++) {
			fprintf(f,"%c", rand() % 26 + 97);
		}
		fprintf(f,"\n");
	}
	return 1;
}
