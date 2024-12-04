/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#define DATE __DATE__
#define TIME __TIME__
#define FILE_NAME __FILE__
#define FUNCNAME __func__
#define LINENUM __LINE__
void system_calls(char *str)
{
	char msg[200];
	int a,fd,res,b;
	fd=open("logfile",O_CREAT |O_WRONLY|O_APPEND,0666);
	if(fd<0)
	{
		printf("open fail\n");
		exit(1);
	}
//	write(fd,DATE,strlen(DATE));
//	write(fd,TIME,strlen(TIME));
//	write(fd,FILE_NAME,strlen(FILE_NAME));
//	write(fd,FUNCNAME,strlen(FUNCNAME));
//	write(fd,LINENUM,sizeof(LINENUM));
//	write(fd,msg,strlen(msg));
//	write(fd,str,strlen(str));
	snprintf(msg, sizeof(msg), "\nFILE: %s\nLINE: %d\nDATE: %s\nTIME: %s\nFUNCTION: %s\nMESSAGE: %s\n\n", FILE_NAME, LINENUM, DATE, TIME, FUNCNAME, str);
    write(fd, msg, strlen(msg));
	write(fd,"\n",strlen("\n"));
	close(fd);
	printf("messeage loged into file\n");
}
void using_apis(char *str)
{
	FILE *f;
	char msg[200];
	f=fopen("logfile","a");
//fprintf(f,"%s",DATE);
//	fprintf(f,"%s",TIME);
//	fprintf(f,"%s",FILE_NAME);
//	fprintf(f,"%s",FUNCNAME);
//	fprintf(f,"%d",LINENUM);
	snprintf(msg, sizeof(msg), "\nFILE: %s\n LINE: %d\n DATE: %s\n TIME: %s\n FUNCTION: %s\n", FILE_NAME, LINENUM, DATE, TIME, FUNCNAME);
	fprintf(f,"%s",msg);
	fprintf(f,"MESSAGE: %s",str);
	fclose(f);
}

int main()
{
	int a,fd,res,b;
	FILE *f;
	char str[100];
	printf("enter choice\n 1.using systemcalls \n 2.using lib APIS: \n");
	scanf("%d",&a);
	printf("enter message to log into the file:\n");
	scanf("%s",str);

	switch(a)
	{
		case 1: //USING SYSTEMCALLS
			system_calls(str);
			break;
		case 2: //USING APIS
			using_apis(str);
				break;
	}
	return 0;
}

