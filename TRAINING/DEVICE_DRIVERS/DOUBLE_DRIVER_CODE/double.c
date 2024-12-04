#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#define DEVICE_PATH "/dev/double_driver"

int main() {
    int num;
	scanf("%d",&num);
    int fd = open(DEVICE_PATH, O_RDWR);

    if (fd < 0) {
        perror("Failed to open device");
        return 1;
    }
	int a=write(fd,&num,sizeof(int));
	if(a<0)
	{
		printf("write fail\n");
		exit(1);
	}
	printf("wrote to device: %d\n",num);
	int num1;
	int ret=read(fd,&num1,sizeof(int));
	if(ret<0)
	{
		printf("read fail\n");
		exit(1);
	}
	printf("read from device: %d\n",num1);
    close(fd);
    return 0;
}
