#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h> // For O_CREAT, O_EXCL
#include <unistd.h>

int main() {
    // Open the same named semaphore
    sem_t *sem = sem_open("/mySemaphore", 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    // Wait (P operation) to decrement the semaphore and enter the critical section
    sem_wait(sem);
    printf("Program B: Reading from the file...\n");
    sleep(2); // Simulate reading
    printf("Program B: Done reading.\n");

    // Signal (V operation) to increment the semaphore and exit the critical section
    sem_post(sem);

    // Close the semaphore
    sem_close(sem);

    return 0;
}

