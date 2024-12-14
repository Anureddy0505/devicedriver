#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

struct logs
{
	char msg[100];
};

int main()
{
	struct logs svar[5];
	int fd=open("/dev/keyvalcir",O_RDWR);
	if(fd==-1)
		printf("open failed\n");
	int i=0;
	char str[100],res[500];
	while(1)
	{
		printf("enter msg: ");
		scanf(" %[^\n]s",svar[i].msg);
		sprintf(str,"%s",svar[i].msg);
		int w=write(fd,str,strlen(str));
		if(w==-1)
			printf("write failed\n");
		int r=read(fd,res,sizeof(res)-1);
		if(r==-1)
			printf("read failed\n");
		else
		{
			res[r]='\0'; // Null-terminate the response string
			printf("logs from kernel:\n%s",res);
		}
		i=(i+1)%5;
		sleep(2);  // Delay to give time for device interaction
	}
	close(fd);
}
