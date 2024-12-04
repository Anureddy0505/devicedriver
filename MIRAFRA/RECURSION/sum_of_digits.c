/*
 * i
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int sumofdig(int n)
{
	int rem;
	if(n==0)
		return;
	else
	{
		rem=n%10;
		return rem+sumofdig(n/10);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",sumofdig(n));
	return 0;
}

