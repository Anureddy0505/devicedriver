/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int sum;
int main()
{
	int a[6]={199,0,-1,1,0,0};
	int i,j,n=6,max=0;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum=sum+a[j];
			if(sum>max)
			{
				max=sum;
			}
		}
	}
	printf("%d",max);
	return 0;
}

