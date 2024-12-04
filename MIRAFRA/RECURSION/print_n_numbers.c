/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
void print(int n)
{
	if(n==0)
		return;
	else
	{
//		printf("%d ",n);
		print(n-1);
	printf("%d ",n);

	}
}
int main()
{
	int n;
	scanf("%d",&n);
	print(n);
	return 0;
}

