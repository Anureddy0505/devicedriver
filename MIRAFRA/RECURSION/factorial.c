/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
	printf("%d ",fact(i));
	}
	return 0;
}

