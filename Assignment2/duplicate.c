#include <stdio.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
	if (argc != 3) {
		printf("error: not enough arguments given\n");
		return -1;
	}

	int fd = open(argv[1], O_RDONLY);

}
