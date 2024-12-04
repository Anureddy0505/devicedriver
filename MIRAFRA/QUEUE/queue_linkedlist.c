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
void traverse();
typedef struct queue
{
	int id;
	struct queue *next;
}queue;
queue *H=NULL,*N=NULL,*T=NULL,*L=NULL;
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
			case 3: traverse(H);
					break;
			default:exit(1);
		}
	}


	return 0;
}
void enqueue(int num)
{
	queue *N=(malloc(sizeof(queue)));
	N->id=num;
	N->next=NULL;
	if(H==NULL)
	{
		H=N;
	}
	else
		L->next=N;
	L=N;
}
void dequeue()
{
	if(H==NULL)
		printf("queue is empty\n");
	else
	{
	T=H->next;
	free(H);
	H=T;
	}
}
void traverse(queue *T)
{
	if(T==NULL)
	{
		printf("nothing to print queue is empty\n");
	}
	while(T)
	{
		printf("%d ",T->id);
		T=T->next;
	}
}
