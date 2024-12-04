/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include<stdio.h>
int main()
{
	int a=mkfifo("fifo1",0666);
	if(a==0)
	{
		printf("fifo created\n");
	}
		else if(errno==EEXIST)
	{
		printf("already exists\n");
	}
	else
	{
		printf("fifo fail\n");
	}
	return 0;
}

