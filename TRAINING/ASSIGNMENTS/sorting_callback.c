/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int asc(int,int);
int desc(int,int);
typedef int (*comp)(int,int);
int sort(int ,int [], comp cmp);
int main()
{
	int n,i;
	printf("enter num of values:\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(n,a,asc);
	printf("ascending: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	sort(n,a,desc);
	printf("\ndescending: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
int sort(int n,int a[], comp cmp)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(cmp(a[i],a[j])<0)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int asc(int a,int b)
{
	return a-b;
}
int desc(int a,int b)
{
	return b-a;
}

