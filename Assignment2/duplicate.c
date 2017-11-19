#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	// check if arguments are correct
	if (argc != 3) {
		printf("duplicate: incorrect arguments\n");
		printf("usage: duplicate <sourcefile> <targetfile>\n");
		exit(0);
	}

	// open source file for reading
	int src_fd = open(argv[1], O_RDONLY);
	
	// check if source file can be read
	if (src_fd == -1) {
		printf("duplicate: cannot find source file '%s'\n", argv[1]);
		exit(src_fd);
	}
	
	// open or create new destination file for writing
	int des_fd = open(argv[2], O_WRONLY | O_CREAT);
	
	// check if destination file can be wrote
	if (des_fd < 0) {
		printf("duplicate: cannot write to destination file '%s'\n", argv[2]);
		exit(des_fd);
	}

	printf("source fd: %d, destination fd: %d\n", src_fd, des_fd);
	
	int BUFF;
	
	
	//File* dest_f = fdopen(src_fd, "w");
}
