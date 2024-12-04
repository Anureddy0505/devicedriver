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
void enqueue(int num);
int pop1();
int pop2();
void push1(int num);
void push2(int num);
void dequeue();
void display();
int top1=-1,top2=-1,count=0;
#define N 5
int s1[N],s2[N];
int main()
{
	int n,num;
	while(1)
	{
		printf("1.enqueue 2.dequeue 3.display 4.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("enter num to enqueue:\n");
					scanf("%d",&num);
					enqueue(num);
					break;
			case 2: dequeue();
					break;
			case 3:display();
				   break;
			case 4: exit(0);
					break;
		}
	}
	return 0;
}

void enqueue(int num)
{
	push1(num);
	count++;
}
int pop1()
{
	return s1[top1--];
}
int pop2()
{
	return s2[top2--];
}
void push1(int num)
{
	if(top1==N-1)
		printf("queue is full cant insert\n");
	else
	{
		top1++;
		s1[top1]=num;
	}
}
void push2(int num)
{
	if(top2==N-1)
		printf("queue is full\n");
	else 
	{
		top2++;
		s2[top2]=num;
	}
}
void dequeue()
{
	int i,a,b;
	if(top1==-1 && top2==-1)
		printf("queue is empty\n");
	else
	{
		for(i=0;i<count;i++)
		{
			a=pop1();
			push2(a);
		}
		b=pop2();
		printf("%d is poped\n",b);
		count--;
		for(i=0;i<count;i++)
		{
			a=pop2();
			push1(a);
		}
	}

}
void display()
{
	if(top1==-1 && top2==-1)
		printf("nothing to print empty\n");
	else
	{
	for(int i=0;i<=top1;i++)
	{
		printf("%d ",s1[i]);
	}
	printf("\n");
	}
}
