/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	char msg[10];
//	const char *path="fifo1";
	int a=open("fifo1",O_RDONLY);
	int b=read(a,msg,sizeof(msg)-1);
	if(b==-1){
		printf("read fail");
		exit(1);
	}
	printf("msg read is of %d bytes\n",b);
	write(1,msg,b);

	return 0;
}

