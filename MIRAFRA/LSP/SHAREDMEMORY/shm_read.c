/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define KEY 555
int main()
{
	int shmid;
	shmid=shmget(KEY, 100,0666|IPC_CREAT);
	if(shmid==-1)
	{
		printf("shared mem creation fail\n");
		exit(1);
	}
	char *a=shmat(shmid,NULL,0);
	printf("enter data you want to send:\n");
	scanf("%99s",a);
	printf("data sent\n");
	shmdt(a);

	return 0;
}

