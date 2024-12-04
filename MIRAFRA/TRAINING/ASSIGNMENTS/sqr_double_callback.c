/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<string.h>
int sqr(int);
int dbl(int);
typedef int (*funcp)(int);
int func(int ,int [], funcp fp);
int main()
{
	int n,i;
	printf("enter num of values:\n");
	scanf("%d",&n);
	int a[n];
	int a1[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//int a1[n]=a;
	memcpy(a1,a,sizeof(a));
	func(n,a,sqr);
	printf("squaring: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}	
	func(n,a1,dbl);
	printf("\ndoubling: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a1[i]);
	}
	printf("\n");
	return 0;
}
int func(int n ,int a[], funcp fp)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		a[i]=fp(a[i]);
	}
}
int sqr(int a)
{
	return a*a;
}
int dbl(int a)
{
	return 2*a;
}


