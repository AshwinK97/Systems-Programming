#include <stdio.h>
#include <stdlib.h>

// swap without temp
int swap(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	return 1;
}

// output sorted array
void print_array(int n, int array[]) {
	int i;
	printf("Sorted: ");
	for (i=0; i<n; i++)
		printf("%d ", array[i]);
	printf("\n");
}

// bubble sort algorithm
int main() {
	// swap counter, loop counter and array size
	int swaps, i, n;
	
	// get array size
	printf("Enter number of elements\n");
	scanf("%d", &n);

	// declare array and get values from user
	int array[n];
	printf("Enter %d integers\n", n);
	for(i=0; i<n; i++)
		scanf("%d", &array[i]);
	
	// loop as long as swaps occur
	do {
		swaps = 0; // set swaps to false on each iteration
		for (i=0; i<n-1; i++) { // iterate array
			if (array[i] > array[i+1])
				swaps += swap(&array[i], &array[i+1]); // swap
		}
	} while(swaps>0); // break if no more swaps occur

	print_array(n, array); // print array
}
