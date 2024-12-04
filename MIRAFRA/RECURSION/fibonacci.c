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
	if(n==0 || n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d is value of %d position",fib(n),n);
	return 0;
}

