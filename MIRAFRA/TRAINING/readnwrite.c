/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
	int f;
	int ret,r;
	char ch;
	f=open("ex.txt",O_WRONLY | O_CREAT);
	write(f,"hello",5);
	close(f);
	f=open("ex.txt",O_RDONLY);

	ret=read(f,&ch,1);
	while(ret!=0)
	{
		write(1,&ch,1);
		ret=read(f,&ch,1);
	
	}
}

