#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h> // For O_CREAT, O_EXCL
#include <unistd.h>

int main() {
    // Open a named semaphore with initial value 1
    sem_t *sem = sem_open("/mySemaphore", O_CREAT, 0644, 1);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    // Wait (P operation) to decrement the semaphore and enter the critical section
    sem_wait(sem);
    printf("Program A: Writing to the file...\n");
    sleep(2); // Simulate writing
    printf("Program A: Done writing.\n");

    // Signal (V operation) to increment the semaphore and exit the critical section
    sem_post(sem);

    // Close the semaphore
    sem_close(sem);

    return 0;
}

