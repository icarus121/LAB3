#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

#define NOMBOR_LENGTH 2

//int pipefds[2];
//int fd;
//pipe(fd);
int nombor[NOMBOR_LENGTH + 1];
int num[NOMBOR_LENGTH + 1];
//int nombor;
/*int getNumber()
{
	//int pipefds[2];
	//int nombor[NOMBOR_LENGTH + 1];
	printf("Masukkan Nombor anda:> \n");
	scanf("Nombor anda adalah %d \n", num);
	//scanf("%d", &nombor);
	write(pipefds[1], nombor, NOMBOR_LENGTH + 1);
	//write(&nombor);

	//printf("Nombor anda adalah %d \n", nombor);
	read(pipefds[0], num, NOMBOR_LENGTH + 1 );
	scanf("Nombor anda adalah %d \n", num);
	return EXIT_SUCCESS;
	//return 0;
	//return nombor;
}*/

int main(void)
{
	int pipefds[2];
	int fd[2];
	pipe(fd);
	pipe(pipefds);
	pid_t pid = fork();
	void sigint_handler(int sig);
	//int num;

	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("Signal");
		exit(1);
	}

	//printf("Masukkan nombor anda: \n");

	if(pipe(pipefds) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	/*if (pid == 0)
	{
		//wait(NULL);
		getNumber();
		exit(EXIT_SUCCESS);
		//return 0;
	}

	else if(pid > 0 )
	{
		wait(NULL);
		if (nombor / 2 != 0)
		{
			printf("The number entered is a prime number");
		}
	}*/
	while(1)
	{
		//int pipefds[2];
		close(0);
		close(fd[1]); //close read fd
		dup(fd[0]);


		if (pid == 0)
		{
			//close(0);
			//close(fd[1]);	//close read fd
			//dup(fd[0]);

			//getNumber();
			//wait(NULL);

			printf("Masukkan Nombor anda:> \n");//enter input
			for (int i =0; i<NOMBOR_LENGTH; i++)
			{
				write(pipefds[);
			}
	     		scanf("Nombor anda adalah %d \n", num);//enter input
			write(pipefds[1], nombor, NOMBOR_LENGTH + 1);//write on pipe
			read(pipefds[0], num, NOMBOR_LENGTH + 1 );//reading from pipe
			close(pipefds[0]);//close read fd
			//scanf("Nombor anda adalah %d \n", num);
	        	//return EXIT_SUCCESS;
			exit(EXIT_SUCCESS);

		}

		else
		{
			wait(NULL);
			printf("Unable to access.");
		}
	}

	//return 0;
	return EXIT_SUCCESS;
}

void sigint_handler(int sig)
{
	printf("Interrupt the process");
}
