/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:1 to 100
 * Sample_Output:
 * *
 * */

#include<stdio.h>
int countofnum(int num);
int reverse(int num);
int main()
{
	int i,j,k,a,b;
	for(i=1;i<=20;i++)
	{
		a=countofnum(i);
		if(a==1)
		{
			printf("%d ",i);
		}
		else
		{
			for(j=1;j<i;j++)
			{
				b=reverse(i);
				//printf("rev %d \n",b);
				if(j==b)
				{
					break;
				}
				else
				{
					printf("%d ",i);
					break;
				}
			}
		}
	}


	return 0;
}
int countofnum(int num)
{
	int r,count=0;
	while(num!=0)
	{
		int r=num%10;
		count++;
		num=num/10;
	}
	return count;
		
}
int reverse(int num)
{
	int r,i,n,rev=0;
	while(num!=0)
	{
		r=num%10;
		rev=rev*10+r;
		num=num/10;
	}
	return rev;
}

