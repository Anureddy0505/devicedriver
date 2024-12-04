/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int main()
{
	int n,i,j,k,temp,c;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf(" \n");
	for(i=0;i<n;i++)
	{
		if((a[i]+1)==a[i+1])
		{
			c=i+1;
			continue;
		}
		else 
			break;
	}
	printf("c is %d",c);
	for(i=0;i<=c;i++)
	{
		printf("%d ",a[i]);

	}

}

