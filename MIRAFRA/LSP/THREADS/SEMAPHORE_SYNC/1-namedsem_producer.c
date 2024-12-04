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
    // Create or get shared memory segment
    int shm_id = shmget(SHM_KEY, sizeof(struct shmseg), IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("Failed to get shared memory");
        exit(1);
    }

    // Attach shared memory segment
    struct shmseg *shm_ptr = (struct shmseg *)shmat(shm_id, NULL, 0);
    if (shm_ptr == (struct shmseg *)-1) {
        perror("Failed to attach shared memory");
        exit(1);
    }

    // Open or create semaphores for empty slots and full slots
    sem_t *sem_empty = sem_open(SEM_EMPTY, O_CREAT, 0666, 1); // Initially 1
    sem_t *sem_full = sem_open(SEM_FULL, O_CREAT, 0666, 0);   // Initially 0

    if (sem_empty == SEM_FAILED || sem_full == SEM_FAILED) {
        perror("Failed to open semaphores");
        exit(1);
    }

    int i = 1;
    for(i;i<10;) {
        // Wait (P operation) on the empty semaphore to ensure space
        sem_wait(sem_empty);

        // Write data to shared memory
        shm_ptr->data = i;
        printf("Producer: wrote %d\n", i);
        i++;

        // Signal (V operation) on the full semaphore to indicate data is ready
        sem_post(sem_full);

        // Sleep for a while to simulate production time
        sleep(1);
    }

    // Detach from shared memory (this part won't be reached in an infinite loop)
    shmdt(shm_ptr);

    return 0;
}
