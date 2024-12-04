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
void print_array();
#define SIZE 5
int rear=-1;
int front=-1;
int queue[SIZE];
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
		case 3: print_array();
				break;
		default:exit(1);
	}
	}	
	return 0;
}
void enqueue(int num)
{
	if(rear==SIZE-1)
		printf("queue is FULL\n");
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		queue[rear]=num;
	}
	else
	{
		rear++;
		queue[rear]=num;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
		printf("queue is empty\n");
	else if(front==rear)
		front=rear=-1;
	else
		front++;
}
void print_array()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
}

