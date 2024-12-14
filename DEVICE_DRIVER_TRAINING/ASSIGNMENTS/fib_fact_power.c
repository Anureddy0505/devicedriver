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
int fib(int);
int fact(int);
int power(int,int);
int (*fp[])(int)={fib,fact};//function pointer array assigned with function name
int (*fp1)(int,int)=power;
int main()
{
	while(1)
	{
		int m,n,a;
		printf("enter choice\n 1.fib\n 2.fact\n 3.power\n 0.exit:\n");//asking from user choice 
		scanf("%d",&a);//input choice from user
		if(a==0)//to exit from menu
		{
			break;
		}
		printf("enter value:\n");
		//scanf("%d%d",&m,&n);
		if(a==1)
		{
			scanf("%d",&m);

			printf("fib: %d\n",fp[0](m));//fibonacci
		}
		else if(a==2)
		{
			scanf("%d",&m);

			printf("fact: %d\n",fp[1](m));//factorial
		}
		else if(a==3)
		{
			scanf("%d%d",&m,&n);

			printf("power: %d\n",fp1(m,n));//power
		}
	}

}

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}

int fib(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

int power(int m,int n)
{
	if(n==0)
		return 1;
	else
		return m*power(m,--n);
}
