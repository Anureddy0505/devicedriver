/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int sumofn(int n)
{
	int sum=0;
	if(n==0)
		return sum;
	else
		return n+sumofn(n-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",sumofn(n));
	return 0;
}

