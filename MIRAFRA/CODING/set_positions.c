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
	int x,pos;
	scanf("%d",&x);
	printbinary(x);
	scanf("%d",&pos);
	int tot=sizeof(x)*8;
	for(i=0;i<tot;i++);
	{
		if(i<pos)
		{

		}

	}
	return 0;
}
void printbinary(int x)
{
	int count=0,i;
	for(i=0;i<sizeof(x)*8;i++)
	{
		count++;
		if(x&0x1<<sizeof(x)*8-1)
		{
			printf("1");
			if(count%4==0)
				printf(" ");
		}
		else{
			printf("0");
			if(count%4==0)
				printf(" ");
		}
		x=x<<1;
	}
	printf("\n");
}


