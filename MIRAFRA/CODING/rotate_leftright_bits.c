/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int totalbits;
void printbinary(char);
int main()
{
	int n,temp=1,i,j;
	char ch,num;
	printf("enter num and positions to shift: ");
	//printf("right or left shift r or l: ");
	scanf("%c%d",&num,&n);
	printf("right or left shift r or l: ");
 	scanf(" %c",&ch);
	printbinary(num);
	printf("\n");
	for(i=0;i<sizeof(num)*8;i++)
	{
		if(temp!=0)
			totalbits++;
		temp=temp<<1;
	}

	printf("tot: %d  \n",totalbits);
	if(ch=='r')
	{
		num=(num>>n)|(num<<(totalbits-n));
	}

	else if(ch=='l')
	{
		num=(num<<n)|(num>>(totalbits-n));
	}
	printf("%x\n",num);
	printbinary(num);
	return 0;
}
void printbinary(char num)
{
	int i;
	for(i=0;i<sizeof(num)*8;i++)
	{
		if(num&(0x1<<(sizeof(num)*8)-1))
			printf("1");
		else
			printf("0");
		num=num<<1;	
	}
	printf("\n");
}


