#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DEVICE_PATH "/dev/keyvalcir1"

int write_to_kernel();
int read_from_kernel();

struct kv_pair {
    int index;
    int key;
    char value[50];
};

#define MAX_KV_PAIRS 3  // Define the max number of key-value pairs in the buffer
int count = 0;
struct kv_pair kv[MAX_KV_PAIRS];

int main() {
    int index;
    int fd;

    while (1) {
        char buff1[100] = {0};
        fd = open(DEVICE_PATH, O_RDWR);
        if (fd == -1) {
            perror("Failed to open device");
            return 1;
        }

        printf("Enter data to send (index, key, value):\n");
        scanf("%d %d %49s", &kv[count].index, &kv[count].key, kv[count].value);

        ssize_t bytes_written = write(fd, &kv[count], sizeof(struct kv_pair));
        if (bytes_written < 0) {
            perror("Failed to write to device");
            close(fd);
            return 1;
        }

        printf("Written to kernel buffer\n");

        ssize_t bytes_read = read(fd, buff1, sizeof(buff1) - 1);
        if (bytes_read < 0) {
            perror("Failed to read from device");
            close(fd);
            return 1;
        }

        printf("%s\n", buff1);
        buff1[bytes_read] = '\0';

        if (strcmp(buff1, "Write limit exceeded") == 0) {
            close(fd);
            break;
        }

        count = (count + 1) % MAX_KV_PAIRS;  // Circular buffer logic
        
        close(fd);
    }

    char buff[100] = {0};
    printf("Enter index to send to kernel:\n");
    scanf("%d", &index);
    fd = open(DEVICE_PATH, O_RDWR);

    ssize_t bytes_written = write(fd, &index, sizeof(int));
    if (bytes_written < 0) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }

    // Attempt to read the message back
    ssize_t bytes_read = read(fd, buff, sizeof(buff) - 1);
    if (bytes_read < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }
    buff[bytes_read] = '\0'; // Null-terminate the string
    printf("%d\n", bytes_read);
    printf("%s\n", buff);

    close(fd);

    return 0;
}

