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
//	msg.type=3;
	while(1)
	{
		printf("waiting to rcv:\n");
		int b=msgrcv(qid,&msg,sizeof(msg),33,0);
		if(b<0)
		{
			printf("fail");
			exit(0);
		}
		printf("No. of bytes received %d\n",b);
		printf("Received mesage is %s\n",msg.msgs);



		msg.type=3;
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
	}
}
