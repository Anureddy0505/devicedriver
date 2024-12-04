/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);
int mod(int,int);
typedef struct // Define a structure with two integers and a function pointer

{
	int a;
	int b;
	int (*fp)(int,int);//function pointer in structures
}st;
int main()
{
	st stu;
	int res;
	printf("enter two values:\n");
	scanf("%d%d",&stu.a,&stu.b);
    // Assign the function pointer to the 'add' function and call it
	stu.fp=add;
	res=stu.fp(stu.a,stu.b);
	printf("add: %d\n",res);
    // Assign the function pointer to the 'sub' function and call it
	stu.fp=sub;
	res=stu.fp(stu.a,stu.b);
	printf("sub: %d\n",res);
    // Assign the function pointer to the 'mul' function and call it
	stu.fp=mul;
	res=stu.fp(stu.a,stu.b);
	printf("mul: %d\n",res);
    // Assign the function pointer to the 'div' function and call it
	stu.fp=div;
	res=stu.fp(stu.a,stu.b);
	printf("div: %d\n",res);
    // Assign the function pointer to the 'mod' function and call it
	stu.fp=mod;
	res=stu.fp(stu.a,stu.b);
	printf("mod: %d\n",res);	
	return 0;//returns 0 successful
}
// Adds two numbers and returns the result
int add(int a,int b)
{
	return a+b;
}
// subtracts two numbers and returns the result

int sub(int a,int b)
{
	return a-b;
}
// multiplies two numbers and returns the result

int mul(int a,int b)
{
	return a*b;
}

// divides two numbers and returns the result

int div(int a,int b)
{
	return a/b;
}
// modulo division of  two numbers and returns the result

int mod(int a,int b)
{
	return a%b;
}


