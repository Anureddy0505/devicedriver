/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
void myfunc(int sig)
{
	printf("Ouchh..! recieved signal %d\n",sig);
//	(void) signal(SIGINT,SIG_DFL);
}
int main()
{
	(void) signal(SIGINT,myfunc);
	while(1)
	{
		printf("hello world !\n");
	sleep(1);
	}
		return 0;
}

