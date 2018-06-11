#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	//printf("hello world (pid:%d)\n", (int) getpid());
	int rc = fork();
	if(rc < 0)
	{
		//fork failed; exit
		fprintf(stderr, "fork failed\n" );
		exit(1);
	}
	else if (rc == 0)
	{//child new process
		close(STDOUT_FILENO);
		open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		//printf("hello, I am child (pid:%d)\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("ls");
		myargs[1] = strdup("./");//strdup("p4.c");
		myargs[2] = NULL;
		execvp(myargs[0],myargs);
		printf("this shouldn't print out\n");
	}
	else
		{//child new process
			int rc_wait = wait(NULL);
		//printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
		//rc, rc_wait, (int) getpid());
	}
	return 0;
}