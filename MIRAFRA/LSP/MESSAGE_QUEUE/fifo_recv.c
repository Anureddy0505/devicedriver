#include<string.h>
#include<fcntl.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	char *msg;	
//	int c=mkfifo("f2",0666);
	int cd=open("f2",O_RDONLY);
	read(cd,msg,strlen(msg));
	printf("message is read %s",msg);

	scanf("%s",msg);
	int a=mkfifo("f2",0666|O_CREAT);
	int b=open("f2",O_WRONLY);
	write(b,msg,strlen(msg));
	printf("%d bytes written and msg is %s\n",b,msg);
	return 0;
}

