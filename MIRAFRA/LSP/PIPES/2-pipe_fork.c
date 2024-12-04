#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int data_processed;
    int file_pipes[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    // Initialize buffer to ensure it's empty
    memset(buffer, '\0', sizeof(buffer));

    // Create the pipe
    if (pipe(file_pipes) == 0) {
        fork_result = fork(); // Fork the process

        if (fork_result == -1) {
            // Fork failed
            fprintf(stderr, "Fork failure\n");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) {
            // Child process
            close(file_pipes[1]); // Close the write end in the child
            data_processed = read(file_pipes[0], buffer, BUFSIZ);
            printf("Read %d bytes: %s\n", data_processed, buffer);
            close(file_pipes[0]); // Close the read end
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(file_pipes[0]); // Close the read end in the parent
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("Wrote %d bytes\n", data_processed);
            close(file_pipes[1]); // Close the write end
        }
    }
    exit(EXIT_SUCCESS);
}

