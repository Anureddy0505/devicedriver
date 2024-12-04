#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int data_processed;
    char buffer[BUFSIZ + 1]; // Buffer to store data
    int file_descriptor;

    memset(buffer, '\0', sizeof(buffer)); // Initialize buffer to zero

    // Extract the file descriptor from the argument passed by the parent
    sscanf(argv[1], "%d", &file_descriptor);

    // Read data from the pipe using the file descriptor
    data_processed = read(file_descriptor, buffer, BUFSIZ);

    // Print how many bytes were read and the data itself
    printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);

    exit(EXIT_SUCCESS); // Exit the program
}

