/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
*/

#include<stdio.h>
int array_fun(int n,int a[]);
void array_rev(int n,int a[]);
void print_array(int n,int a[]);
int main()
{
	int i,n;
	printf("enter size of array:\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int m=n;int k=n;
	for(i=0;i<n;i++)
	{
		int max_index=array_fun(m,a);
		printf("max:%d \n",max_index);
		array_rev(max_index+1,a);
		print_array(n,a);
		array_rev(k,a);
		print_array(n,a);
		m--;
		k--;
	}
	return 0;
}
int array_fun(int n,int a[])
{
	int i,index=0;
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			index=i;
		}
		else
			max=max;
	}
	return index;
}

void array_rev(int n,int a[])
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}
void print_array(int n,int a[])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
