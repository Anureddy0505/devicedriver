#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DEVICE_PATH "/dev/keyvalue"
int write_to_kernel();
int read_from_kernel();
struct kv_pair
{
	int index;
	int key;
	char value[50];
};
int count=0;
struct kv_pair kv[3];
int main() {
	int choice;
 	while(1)
	{
		printf("enter 1.to write to kernel soace\n 2.to read from kernel space\n 3.exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			write_to_kernel();
			count++;
		}
		else if(choice==2)
		{
			read_from_kernel();
		}
		else
		{
			break;
		}
	}
}
int write_to_kernel()
{
   int fd = open(DEVICE_PATH, O_RDWR);
	if(fd==-1)
	{
		printf("open fail");
		return 1;
	}
	printf("enter data to send index,key,value: \n");
	scanf("%d %d %49s",&kv[count].index,&kv[count].key,kv[count].value);
	ssize_t bytes_write = write(fd, &kv[count], sizeof(kv));
    if (bytes_write < 0) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }
	printf("Written to kernel buffer\n");
	close(fd);
}

int read_from_kernel()
{
  	int fd = open(DEVICE_PATH, O_RDWR);
	if(fd==-1)
	{
		printf("open fail");
		return 1;
	}
	char buff[100];
	read(fd,buff,strlen(buff));
	printf("from kernel: %s\n",buff);
	close(fd);
}
