/*
 * i
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

static int alarm_fired = 0;

// Signal handler for SIGALRM
void alarm_handler(int sig) {
    alarm_fired = 1;  // Set the flag when the alarm goes off
}

void sig_hand(int sig)
{
	printf("recevied signal alarm");
alarm_fired=1;	
}
int main() {
    int seconds;

    // Ask the user for the number of seconds for the alarm
    printf("Enter the number of seconds for the alarm: ");
    scanf("%d", &seconds);

    // Set up the signal handler for SIGALRM
   // signal(SIGALRM, alarm_handler);

    // Set the alarm
    alarm(seconds);
	signal(SIGALRM,sig_hand);
    // Pause the program until the alarm goes off
	
    printf("Waiting for the alarm to go off...\n");
    while (!alarm_fired) {
       // pause();  // Wait for the signal:wq
		}

    // When the alarm goes off
    printf("Ding! The alarm has gone off!\n");

    return 0;
}


