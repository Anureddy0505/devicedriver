#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int add(int,int);
int sub(int,int);
int mul(int,int);
int divi(int,int);
int mod(int,int);
enum fun//enum initalization
{
	Add,Sub,Mul,Div,Mod
};
//int (*fp[])(int,int)={add,sub,mul,div,mod};
typedef struct 
{
	int (*fp[5])(int,int);//function pointer
}st;
int main(int argc, char *argv[])
{
	st stu;
	enum fun f;
	int index;
	int res;
	char *ch=argv[1];//string from command line argument
	int a=atoi(argv[2]);//input from CLA 
	int b=atoi(argv[3]);// input from CLA
	//ASSIGNING FUNCTIONS TO EACH FUNCTION POINTER
	stu.fp[0]=add;
	stu.fp[1]=sub;
	stu.fp[2]=mul;
	stu.fp[3]=divi;
	stu.fp[4]=mod;
	if(strcmp(ch,"add")==0)//comparing the string from command line argument
	{
		index=Add;//assigning enum
	}
	else if(strcmp(ch,"sub")==0)
	{
		index=Sub;
	}
	else if(strcmp(ch,"mul")==0)
	{
		index=Mul;
	}
	else if(strcmp(ch,"div")==0)
	{
		index=Div;
	}

	else if(strcmp(ch,"mod")==0)
	{
		index=Mod;
	}
	res=stu.fp[index](a,b);//assigning the index coming from conditions
	printf("res: %d \n",res);
	return 0;
}

int add(int a,int b)//add function
{
	return a+b;
}
int sub(int a,int b)//sub function
{
	return a-b;
}
int mul(int a,int b)//multiplication function
{
	return a*b;
}
int divi(int a,int b)//div function
{
	return a/b;
}
int mod(int a,int b)//modulo function
{
	return a%b;
}


