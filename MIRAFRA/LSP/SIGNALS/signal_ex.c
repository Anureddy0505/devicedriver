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

static int signal_received = 0;

// Signal handler
void signal_handler(int sig) {
    signal_received = 1;  // Set flag when signal is received
}

int main() {
    // Set up the signal handler
    signal(SIGUSR1, signal_handler);
	alarm(5);
    // Simulate waiting for a signal
    printf("Waiting for signal...\n");
    while (!signal_received) {
        pause();  // Wait for a signal
    }

    printf("Signal received!\n");
    return 0;
}

