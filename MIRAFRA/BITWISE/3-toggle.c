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
	int n,k;
	scanf("%d%d",&n,&k);
	n=n^(0x1<<k);
	printf("%d",n);
	return 0;
}

