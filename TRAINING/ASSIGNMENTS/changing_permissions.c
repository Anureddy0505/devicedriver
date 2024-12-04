/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	struct stat s;
	int a=stat("abc.txt",&s);
	printf("before changing mode: %lo (octal)",(unsigned long)s.st_mode & 0777);
	chmod("abc.txt",0666);
	a=stat("abc.txt",&s);
	printf("after changing permissions mode: %lo (octal)",(unsigned long)s.st_mode & 0777);
	
	return 0;
}

