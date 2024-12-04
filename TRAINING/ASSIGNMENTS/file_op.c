/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	int fd=open("abc.txt",O_RDWR);
	if(fd==-1)
	{
		printf("open fail");
		return 1;
	}
	write(1,"hello",5);
	write(fd,"hello",5);
	return 0;
}

