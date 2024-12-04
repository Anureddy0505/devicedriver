#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <unistd.h>

#define SHM_KEY 1234         // Shared memory key
#define SEM_EMPTY "/sem_empty"  // Semaphore name for empty slot
#define SEM_FULL "/sem_full"    // Semaphore name for full slot

struct shmseg {
    int data;
};

int main() {
    // Get the shared memory segment
    int shm_id = shmget(SHM_KEY, sizeof(struct shmseg), 0666);
    if (shm_id == -1) {
        perror("Failed to get shared memory");
        exit(1);
    }

    // Attach to shared memory segment
    struct shmseg *shm_ptr = (struct shmseg *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (struct shmseg *)-1) {
        perror("Failed to attach shared memory");
        exit(1);
    }

    // Open semaphores for empty slots and full slots
    sem_t *sem_empty = sem_open(SEM_EMPTY, 0);  // 0 for open existing semaphore
    sem_t *sem_full = sem_open(SEM_FULL, 0);    // 0 for open existing semaphore

    if (sem_empty == SEM_FAILED || sem_full == SEM_FAILED) {
        perror("Failed to open semaphores");
        exit(1);
    }

    for(int i=1;i<10;i++){
        // Wait (P operation) on the full semaphore to ensure data is available
        sem_wait(sem_full);

        // Read data from shared memory
        printf("Consumer: read %d\n", shm_ptr->data);

        // Signal (V operation) on the empty semaphore to indicate space is available
        sem_post(sem_empty);

        // Sleep for a while to simulate consumption time
        sleep(2);
    }

    // Detach from shared memory (this part won't be reached in an infinite loop)
    shmdt(shm_ptr);
     sem_unlink(SEM_EMPTY);
	 sem_unlink(SEM_FULL);
    return 0;
}
