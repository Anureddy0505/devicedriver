/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	n=n|(0x1<<p);
	printf("%d",n);
	return 0;
}

