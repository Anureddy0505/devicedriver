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
void enqueue(int);
void dequeue();
void print();
typedef struct que
{
	int data;
	struct que *next;
}queue;
queue *X=NULL,*N=NULL,*H=NULL,*L=NULL,*T=NULL;
int main()
{
	int n,num;
	while(1)
	{
	printf("enter 1.enqueue 2.dequeue 3.print 4.stop\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1: printf("enter num to enqueue\n");
				scanf("%d",&num);
		   		enqueue(num);
				break;
		case 2: dequeue();
				break;
		case 3: print();
				break;
		default:exit(1);
	}
	}
	return 0;
}
void enqueue(int num)
{
	queue *N=(queue *)(malloc(sizeof(struct que)));
	N->data=num;
	N->next=NULL;
	if(H==NULL)
	{
		H=N;
	}
	else
	{
		L->next=N;
		N->next=H;
	}
	L=N;
}
void dequeue()
{
	if(H==NULL)
		printf("empty queue\n");
	else
	{
		X=H->next;
		L->next=X;
		free(H);
		H=X;
	}
}
void print()
{
	if(H==NULL)
		printf("nothing to print empty queue\n");
	else
	{
		T=H;
	do
	{
		printf("%d ",T->data);
			T=T->next;
	}while(T!=H);
	}
}
