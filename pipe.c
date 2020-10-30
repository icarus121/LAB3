#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define NOMBOR_LENGTH 2

int getNombor()
{
	int pipefds[2];
	int nombor;
	printf("Nombor:");
        scanf("%d", &nombor);//get the input
	close(pipefds[1]);//close write
        write(pipefds[1], &nombor, NOMBOR_LENGTH + 1);

        read(pipefds[0], &nombor, NOMBOR_LENGTH + 1);
        printf("Nombor anda: %d\n", nombor);
	//close(pipefds[0]);//close read

	if(nombor %2 != 0)
	{
		printf("The number, %d entered is a prime number. \n", nombor);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("The number is even\n");
	}

	//return &nombor;
}

void getSignal()
{
	void sigint_handler(int sig);

	if(signal(SIGINT,sigint_handler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
}

int main(void)
{

	//int pipe;
	int pipefds[2];
	//int pipe(pipefds);
	//int nombor;
	pid_t pid = fork();

	getSignal();

	if (pipe(pipefds)==-1)
	{
		perror("Pipe fail");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		getNombor();//call the function
		//close(pipefds[0]);//close read
		/*if(getNombor /2 != 0)
        	{
                	printf("The number, %d entered is a prime number", nombor);
		}*/

		exit(EXIT_SUCCESS);
	}

	if (pid > 0)
	{
		wait(NULL);

		//close(pipefds[1]);
		//read(pipefds[0], &nombor, NOMBOR_LENGTH + 1);
		//close(pipefds[0]);//close read

		//printf("Nombor anda:%d \n", nombor);

		/*if(getNombor() /2 != 0)
		{
			int num = getNombor(&nombor);
			printf("The number, %d entered is a prime number", num);
		}*/

	}

	return EXIT_SUCCESS;
}

void sigint_handler(int sig)
{
	printf("This is a CTRL + C Signal\n");
}
