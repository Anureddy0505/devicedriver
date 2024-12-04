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
#include<stdio.h>

#define KEY 555

int main()
{

	int shmid=shmget(KEY,100,0666);
	if(shmid==-1)
	{
		printf("shmget fail\n");
		exit(1);
	}
	char *a=shmat(shmid,0,0);
	printf("data written int shared mem is %s \n",a);
	shmdt(a);

	return 0;
}

