#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/calculator_device"

int main() {
    char buffer[100];
	char str[100];
    int fd = open(DEVICE_PATH, O_RDWR);

    if (fd < 0) {
        perror("Failed to open device");
        return 1;
    }
	printf("enter data like ( 2 2 +) :\n"); 
	scanf("%[^\n]s",buffer);

    ssize_t bytes_write = write(fd, buffer, strlen(buffer));

    if (bytes_write < 0) {
        perror("Failed to wirte to device");
        close(fd);
        return 1;
    }
	

	ssize_t bytes_read = read(fd, str, sizeof(str)-1);
	printf("%d bits read from buff\n",bytes_read);
    if (bytes_read < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    str[bytes_read] = '\0'; // Null-terminate the string
    printf("Data from calculator driver: %s\n", str);

    close(fd);
    return 0;
}


