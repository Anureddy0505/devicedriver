/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE];
int push(int ,int *);
int pop(int *);
void print(int *);
int main()
{
	int top=-1;
	int n,num;
	while(1)
	{
		printf("enter 1.push 2.pop 3.print\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter num to push\n");
				scanf("%d",&num); 
				push(num,&top);
				   break;
			case 2:pop(&top);
				   break;
			case 3:print(&top);
				   break;
			default: exit(0);
		}
	}
	return 0;
}
int push(int num,int *top)
{
	if((*top)==SIZE-1)
		printf("stack is full\n");
	else
	{
		(*top)++;
		stack[*top]=num;
		printf("%d is pushed to stack s[%d]\n",num,*top);
	}
}
int pop(int *top)
{
	if(*top==-1)
		printf("stack is empty\n");
	else
	{
		printf("%d is removed from stack %d\n",stack[*top],*top);
		(*top)--;
	}
}
void print(int *top)
{
	int i;
	for(i=0;i<=(*top);i++)
	{
		printf("%d ",stack[i]);
	}
}

