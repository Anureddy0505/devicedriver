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
	if(n<=2)
		return (n<2)?1:0;
	if(n==i)
		return 0;
	else if(n%i==0)
		return 1;
	else
		prime_or_not(n,i+1);
}
int main()
{
	int j=2,i,a,b;
	printf("enter range: ");
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	{
		int x=prime_or_not(i,j);
		if(x==0)
			printf("%d is prime\n",i);
		else if(x==1)
			printf("%d is not prime\n",i);
	}
	return 0;
}

