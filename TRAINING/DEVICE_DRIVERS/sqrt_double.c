#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
	static int num;
	printf("enter number:\n");
	scanf("%d",&num);

	int fd=open("/dev/simple_device", O_RDWR);
	if(fd<0)
	{
		printf("open fail\n");
		exit(1);
	}

	int a=write(fd,&num,sizeof(int));
	if(a<0)
	{
		printf("write fail\n");
		exit(1);
	}
	printf("written to buff: %d\n",a);
	static int num1, num2;
	int ret = read(fd,&num1,sizeof(int));
	printf("read from buff: %d\n",ret);
	num1=num1*2;
	int ret1=write(fd,&num1,sizeof(int));
	printf("%d bytes written to buff\n",ret1);
	close(fd);


	int fd1=open("/dev/simple_device", O_RDWR);
	ret = read(fd1,&num2,sizeof(int));
	printf("number from buff kernel space is\n");

	printf("%d",num2);
	printf("\n");
	close(fd1);
	return 0;
}


