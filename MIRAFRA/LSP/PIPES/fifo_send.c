/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<string.h>
#include<fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{

	char msg,msg1;
	int a=mkfifo("f1",0666);
	int c=mkfifo("f2",0666);
	int b=open("f1",O_WRONLY);
	int cd=open("f2",O_RDONLY);
	while(1)
	{
	printf("enter message to send\n");
	scanf("%c",&msg);
	write(b,msg,1);
	printf("the received msg is ");
	int n=read(cd,msg1,1);
	write(1,msg1,n);
	printf("\n");

	}
	return 0;
}

