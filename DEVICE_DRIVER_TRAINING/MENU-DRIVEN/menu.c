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
int add(int,int);
int sub(int,int);
int mul(int,int);
int divi(int,int);
int mod(int,int);
int (*fp[])(int,int)={add,sub,mul,divi,mod};//function pointer array assigned with function name
int main()
{
	while(1)
	{
		int m,n,a;
		printf("enter choice\n 1.add\n 2.sub\n 3.mul\n 4.div\n 5.modulo\n 0.exit:\n");//asking from user choice 
		scanf("%d",&a);//input choice from user
		if(a==0)//to exit from menu
		{
			break;
		}
		printf("enter values:\n");
		scanf("%d%d",&m,&n);//reads input 2 vqlues from user
		if(a==1)
		{
			printf("add: %d\n",fp[0](m,n));//a`ddition
		}
		else if(a==2)
		{
			printf("sub: %d\n",fp[1](m,n));//subtraction
		}
		else if(a==3)
		{
			printf("mul: %d\n",fp[2](m,n));//multiplication
		}
		else if(a==4)
		{
			printf("div: %d\n",fp[3](m,n));//division
		}
		else if(a==5)
		{
			printf("mod: %d\n",fp[5](m,n));//modulo division
		}
	}
	return 0;
}
int add(int a,int b)//addition function
{
	return a+b;
}
int sub(int a,int b)//subtraction function
{
	return a-b;
}
int mul(int a,int b)//multiplicatin function
{
	return a*b;
}
int divi(int a,int b)//diviion function
{
	return a/b;
}
int mod(int a,int b)//modulo division function
{
	return a%b;
}

