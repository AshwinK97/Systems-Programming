#include <unistd.h>
#include <stdio.h>

int main() {
	printf("my process id: %d\n", getpid());
	return 0;
}
