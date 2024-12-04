/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int prime_or_not(int n,int i)
{
	int count=0;
	if(n<=2)
		return (n<2)?0:1;
	if(n==i)
		return 1;
	else if(n%i==0)
			return 0;
	else
		prime_or_not(n,i+1);
}
int main()
{
	int n,i=2;
	scanf("%d",&n);
	int a=prime_or_not(n,i);
	if(a==0)
		printf("%d is not prime\n",n);
	else
		printf("%d is prime\n",n);
	return 0;
}

