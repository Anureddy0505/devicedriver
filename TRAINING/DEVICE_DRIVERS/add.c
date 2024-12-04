/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
	static int num1,num2;
	char str[10];
	printf("enter two numbers:\n");
	scanf("%d%d",&num1,&num2);
	printf("enter add/sub:\n");
	scanf("%s",str);
	int fd=open("/dev/simple_device",O_RDWR);
	if(fd==-1)
	{
		printf("open fail\n");
		exit(1);
	}
	write(fd,&num1,sizeof(num1));
	write(fd,&num2,sizeof(num2));
	close(fd);


	static int a,b;
	fd=open("/dev/simple_device",O_RDWR);
	read(fd,&a,sizeof(int));
	read(fd,&b,sizeof(int));
	printf("%d %d",a,b);



	return 0;
}

