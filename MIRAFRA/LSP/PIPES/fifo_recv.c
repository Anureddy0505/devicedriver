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
//	int c=mkfifo("f2",0666);
	int cd=open("f1",O_RDONLY);
	int b=open("f2",O_WRONLY);
	while(1)
	{
		printf("waiting for the msg:\n");
		int n=read(cd,msg,1);
		write(1,msg,n);
		printf("enter message\n");
		scanf("%c",&msg1);
		write(b,msg1,1);
		printf("the msg sent successfully\n");
	}
	return 0;
}

