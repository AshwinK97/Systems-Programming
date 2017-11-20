#include <linux/kernal.h>
#include <unistd.h>
#include <stdio.h>

asmlinkage long sys_noopen(void) {
	pid_t pid = getpid();
	printf("noopen: pid is %d\n", pid);
	return pid;
}
