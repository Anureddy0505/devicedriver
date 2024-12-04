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
	int n,l=1,l1=0,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
		{
			l++;
			if(l>=l1)
				l1=l;
		}
		else 
		{
			l=0;
			continue;
		}
	}
	printf("highest len %d",l1);
	return 0;
}

