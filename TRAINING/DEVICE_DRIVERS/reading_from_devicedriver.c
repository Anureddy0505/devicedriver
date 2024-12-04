/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
	char str[100];
	char ch;
	int fd=open("/dev/simple_device", O_RDWR);
	if(fd<0)
	{
		printf("open fail\n");
		exit(1);
	}
	printf("enter data to write into device: \n");
	scanf("%s",str);
	int a=write(fd,str,strlen(str));
	if(a<0)
	{
		printf("write fail\n");
		exit(1);
	}
	printf("data is written into device\n");
	int ret = read(fd,&ch,1);
	while(ret!=0)
	{
		write(1,&ch,1);
		ret=read(fd,&ch,1);
	}
	printf("\n");
	close(fd);
	return 0;
}

