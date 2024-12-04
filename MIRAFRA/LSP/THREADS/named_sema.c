#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <fcntl.h>
#include <semaphore.h>
#include <string.h>
#include <sys/wait.h>


#define SHM_KEY 1234       // Shared memory key
#define SHM_SIZE sizeof(int) // Shared memory size

// Function to create shared memory
int create_shared_memory() {
    int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    return shmid;
}

int main() {
    // Create shared memory
    int shmid = create_shared_memory();
    
    // Attach to shared memory
    int *shm_ptr = (int *)shmat(shmid, NULL, 0);
    if (shm_ptr == (int *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Open the named semaphores
    sem_t *sem = sem_open("/sem", O_CREAT, 0666, 1);  // Initially, one empty slot
//    sem_t *full = sem_open("/full", O_CREAT, 0666, 0);   // Initially, no items in the buffer

    if (sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }
	*shm_ptr=0;
    pid_t pid = fork();

    if (pid == 0) {  // Consumer process
        for (int i = 0; i < 100; i++) {
            sem_wait(sem);  // Wait for item to be produced
			*shm_ptr=*shm_ptr+1;
            // Read from shared memory (consume the item)
       //     printf("Consumer: Consumed value %d\n", *shm_ptr);

            sem_post(sem);  // Signal that there is space for the producer

 // Simulate processing time
        }
		
			exit(0);
    } else {  // Producer process
        for (int i = 0; i < 100; i++) {
            sem_wait(sem);  // Wait for empty slot in the buffer

            // Write to shared memory (produce an item)
            *shm_ptr = *shm_ptr + 1;  // Produce item
     //       printf("Producer: Produced value %d\n", *shm_ptr);

            sem_post(sem);  // Signal that there is an item for the consumer

          //  sleep(1); // Simulate processing time
        }

        // Wait for the consumer to finish (optional)
        wait(NULL);

		printf("%d",*shm_ptr);
    }

    // Detach from shared memory
    shmdt(shm_ptr);

    // Clean up
 /*   sem_close(empty);
    sem_close(full);
    sem_unlink("/empty");
    sem_unlink("/full");
    shmctl(shmid, IPC_RMID, NULL);*/

    return 0;
}

