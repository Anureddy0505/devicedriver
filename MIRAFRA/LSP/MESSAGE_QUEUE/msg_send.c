/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>
#define KEY 123
struct message
{
	long int type;
	char msgs[20];
};

int main()
{
	struct message msg;
	int qid=msgget(KEY,0666|IPC_CREAT);
	if(qid<0)
	{
		printf("message queue creation fail\n");
		exit(0);
	}
	//msg.type=33;
	while(1)
	{
		msg.type=33;
		printf("Enter a message:\n");
		scanf("%s",msg.msgs);
		int a=msgsnd(qid,&msg,sizeof(msg),0);
		if(a<0)
		{
			printf("message send fail\n");
			exit(0);
		}
		//printf("returned %d\n",a);
		printf("message sent\n");

		int b=msgrcv(qid,&msg,sizeof(msg),3,0);
		if(b<0)
		{
			printf("message receive fail\n");
			exit(0);
		}
		printf("Recived msg is %s\n",msg.msgs);
	}
	return 0;
}

