#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int main(int argc, char *argv[]) {
	FILE *f; // pointer for output file
	
	// open input.txt and check if it is writable
	if ((f=fopen("spam.txt", "w")) == NULL) {
		printf("Unable to open 'spam.txt' for writing\n");
		exit(0);
	}
	
	clock_t begin = clock(); // get start time
	printf("generate function returned with: %d\n", generate(f)); // call generate function
	double runtime = (double)(clock() - begin) / CLOCKS_PER_SEC; // get runtime = end - start
	printf("runtime: %fs\n", runtime); // display runtime
}
