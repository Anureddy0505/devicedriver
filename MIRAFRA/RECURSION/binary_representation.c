/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
void bin(int n)
{
	if(n==0)
		return;
	else
	{
		bin(n/2);
		printf("%d",n%2);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	bin(n);
	return 0;
}

