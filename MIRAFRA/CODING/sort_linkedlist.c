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
typedef struct student
{
	int id;
	struct student *next;
}stu;
stu* createlist();
stu* createnode();
stu* sortlist(stu*);
void traversal(stu* T);
int main()
{
	stu* H=NULL;stu* N=NULL; stu* L=NULL;
	printf("enter y/n ");
	char ch;
	scanf("%c",&ch);
	while(ch=='y')
	{
		N=createnode();
		if(H==NULL)
		{
			H=N;
		}
		else
		{	
			L->next=N;
		}
		L=N;
		printf("enter y/n ");
		scanf(" %c",&ch);
	}
	sortlist(H);
	traversal(H);
	return 0;
}
stu* createnode()
{
	stu *N=malloc(sizeof(stu));
	printf("enter id ");
	scanf("%d",&N->id);
	N->next=NULL;
	return N;
}
void traversal(stu* T)
{
	while(T)
	{
		printf("%d ",T->id);
		T=T->next;
	}
}
stu* sortlist(stu* H)
{
	stu *p1,*p2;
	int temp;
	p1=H;
	p2=H;
	while(p1->next!=NULL)
	{
		while(p2->next!=NULL)
		{
			if(p2->id > p2->next->id)
			{
				temp=p2->id;
				p2->id=p2->next->id;
				p2->next->id=temp;
			}
				p2=p2->next;
		}
		p2=H;
		p1=p1->next;
	}

}
