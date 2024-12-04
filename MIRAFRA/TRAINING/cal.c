/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<string.h>
int (*p)(int,int);
int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int mod(int,int);
int *func(int (*p)(int,int),int,int);
int main(int argc,char *argv[])
{
	int a,b,res;
	char ci=(argv[1]);
	printf("enter two values\n");
	scanf("%d%d",&a,&b);
	switch(ci)
	{
		case '+': func(add,a,b);
				  break;
		case '-': func(sub,a,b);
				  break;
	     case '*': func(mul,a,b);
		     	   break;
		case '/': func(div,a,b);
				  break;
		case '%': func(mod,a,b);
				  break;
	}
}
int *func(int (*p)(int,int),int a,int b)
{
	printf("%d ", p(a,b));
}
int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
int mod(int a,int b)
{
	return a%b;
}

