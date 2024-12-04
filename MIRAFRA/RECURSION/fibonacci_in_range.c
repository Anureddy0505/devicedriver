/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int fib(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}
int main()
{
	int i,a,b;
	printf("enter range:\n");
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		printf("%d ",fib(i));
	}
	return 0;
}

