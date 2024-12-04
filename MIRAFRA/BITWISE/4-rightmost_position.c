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
	int n,c=0,i;
	scanf("%d",&n);
	int temp=n;
	for(i=0;i<sizeof(n)*8;i++)
	{
		if(n&(0x1<<i))
		{
			c=i;
			break;
		}

	}
	printf("right most pos is %d\n",c);
	//temp=temp|(0x1<<c);
	//printf(" num is %d ",temp);
	return 0;
}


