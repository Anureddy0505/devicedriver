#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main()
{
	char ch;
	FILE *f=fopen("example.txt","w");
	int fd=fileno(f);
	write(fd,"hello ash",9);
	fclose(f);
	f=fopen("example.txt","r");
	int fd1=fileno(f);
	int r=read(fd1,&ch,1);
	while(r!=0)
	{
		write(1,&ch,1);
		r=read(fd1,&ch,1);
	}
}

