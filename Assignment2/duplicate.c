#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// display message while duplicating
void display_message(int s) {
     printf("duplicate: still duplicating...\n" ); // display message
     alarm(1); // set for 1 second
     signal(SIGALRM, display_message); // setup another alarm
}

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
	if (src_fd < 0) {
		printf("duplicate: '%s': %s\n", argv[1], strerror(errno)); // use errno to print error
		exit(-1);
	}
	
	// open or create new destination file for writing
	int des_fd = open(argv[2], O_WRONLY | O_CREAT);
	
	// check if destination file can be wrote
	if (des_fd < 0) {
		printf("duplicate: '%s': %s\n", argv[2], strerror(errno)); // use errno to print error
		exit(-1);
	}
	
	char c; // character buffer for reading
	int bytes = 0; // store the number of bytes read
	
	signal(SIGALRM, display_message); // set up alarm
    alarm(1); // only display message after 1 second

	// attempt to read 1 byte from source, loop as long as byte is read
	while (read(src_fd, &c, 1) == 1) {
		// attempt to write 1 byte to destination, if cannot write then disk is full
		if (write(des_fd, &c, 1) != 1) {
			printf("duplicate: %s\n", strerror(errno)); // use errno to print error
			exit(-1);
		}
		bytes++; // increment the number of bytes read
	}

	// output number of bytes copied from source to destination
	printf("duplicate: copied %d bytes from '%s' to '%s'\n", bytes, argv[1], argv[2]);
}
