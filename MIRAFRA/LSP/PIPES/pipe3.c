#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int data_processed;
    int file_pipes[2]; // The pipe file descriptors
    const char some_data[] = "12344"; // Data to write into the pipe
    char buffer[BUFSIZ + 1]; // Buffer to store data
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer)); // Initialize the buffer to zero

    // Create the pipe
    if (pipe(file_pipes) == 0) {
        // Fork the process
        fork_result = fork();

        if (fork_result == (pid_t)-1) {
            // Fork failed
            fprintf(stderr, "Fork failure\n");
            exit(EXIT_FAILURE);
        }

        if (fork_result == 0) {
            // Child process
            // Convert the read end file descriptor to a string
            sprintf(buffer, "%d", file_pipes[0]);
            // Replace the child process with the "pipe4" program, passing the file descriptor as argument
            (void)execl("pipe4","pipe4", buffer, (char *)0);
            // If execl() fails, exit with failure
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            // Write data to the pipe
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("%d - wrote %d bytes\n", getpid(), data_processed);
        }
    }

    exit(EXIT_SUCCESS); // Exit the program
}

