#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/calculator_device"

int main() {
    char buffer[100];
    char result[100];
    int fd = open(DEVICE_PATH, O_RDWR);

    if (fd < 0) {
        perror("Failed to open device");
        return 1;
    }

    // Read input from user
    printf("Enter calculation (e.g., 2 3 +): ");
    scanf("%[^\n]s", buffer);

    ssize_t bytes_write = write(fd, buffer, strlen(buffer));

    if (bytes_write < 0) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }

    ssize_t bytes_read = read(fd, result, sizeof(result) - 1);
    if (bytes_read < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    result[bytes_read] = '\0';  // Null-terminate the string
    printf("Data from calculator driver: %s\n", result);

    close(fd);
    return 0;
}

