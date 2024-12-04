/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static int sigint_count = 0;

// Signal handler for SIGINT
void handle_sigint(int sig) {
    sigint_count++;
    printf("Caught SIGINT (%d)\n", sigint_count);
    
    if (sigint_count >= 3) {
        printf("Exiting program.\n");
        exit(0);
    }
}

int main() {
    struct sigaction sa;
    
    // Specify the handler function
    sa.sa_handler = handle_sigint;
    
    // Clear sa_mask to block no additional signals
    sigemptyset(&sa.sa_mask);

    // Set the SA_RESTART flag to restart system calls if interrupted by this signal
    sa.sa_flags = SA_RESTART;

    // Set the action for SIGINT to our handler
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    printf("Press Ctrl+C (SIGINT) to increment counter. Program will exit after 3 counts.\n");
    
    // Loop indefinitely to wait for signals
    while (1) {
        pause();  // Wait for signals
    }

    return 0;
}

