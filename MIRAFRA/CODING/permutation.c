/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
int main()
{
	char str[3]={'a','b','c'};
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				if( i!=j && j!=k && i!=k)
				{
					printf("%c%c%c\n",str[i],str[j],str[k]);
				}
			}
		}
	}


	return 0;
}

