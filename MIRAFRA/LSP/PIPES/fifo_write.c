/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */
#include<errno.h>
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	const char msga[10]="hello";
	int res = mkfifo("fifo1", 0666);
	int fd=open("fifo1", O_WRONLY);
	int a=write(fd,msga,strlen(msga));
	printf("%d bytes written\n",a);
}
