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
	int arr[6]={1,2,3,4,5,6};
	int n=6,e;
	scanf("%d",&e);
	int k=mergesort(arr,n,e);
		printf("search element is found at %d index",k);
}

int mergesort(int a[], int n,int e)
{
	int i,mid;
	mid=(0+(n-1))/2;
	for(i=0;i<n;i++)
	{
		if(e==a[mid])
			return mid;
		else if(e<a[mid])
			mid=mid-1;
		else
			mid=mid+1;
	}
}
