#include<stdio.h>
char * mystrrev(char *);
int main()
{
	char str[100];
	printf("Enter a string: ");
	scanf("%99[^\n]s",str);
	mystrrev(str);
	return 0;
}
char * mystrrev(char * str)
{
	char temp;
	int i,c=0;
	for(i=0;*(str+i);i++)
	c++;
	for(i=0;i<c/2;i++)
	{
		temp=*(str+i);
		*(str+i)=*(str+c-i-1);
		*(str+c-i-1)=temp;
	}
	printf("%s",str);
}

