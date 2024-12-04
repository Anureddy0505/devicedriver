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
int push(int );
int pop();
void print();
typedef struct stac
{
	int data;
	struct stac *next;
}stack;
stack *top=0;
int main()
{
	int n,num;
	while(1)
	{
		printf("enter 1.push 2.pop 3.print\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter num to push\n");
				scanf("%d",&num); 
				push(num);
				   break;
			case 2:pop();
				   break;
			case 3:print();
				   break;
			default: exit(0);
		}
	}
	return 0;
}
int push(int num)
{
	stack* N=(stack*)(malloc(sizeof(struct stac)));
	N->data=num;
	N->next=top;
	top=N;
	printf("%d is pushed \n",num);
}
int pop()
{
	 stack *T;
	T=top;
	if(top==0)
		printf("stack empty\n");
	else
	{
		printf("pop: %d ",T->data);
		top=top->next;
		free(T);

	}
}
void print()
{
	stack *T;
	T=top;
	if(top==0)
		printf("nothing to print\n");
	else
	{
		while(T)
		{
			printf("%d ",T->data);
			T=T->next;
		}
	}
}
