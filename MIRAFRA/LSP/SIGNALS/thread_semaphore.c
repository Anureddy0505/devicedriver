/*
 * Name: Ashritha Reddy
 * Date:
 * File_name:
 * Sample_Input:
 * Sample_Output:
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared semaphore
sem_t semaphore;

// Function to be run by threads
void* access_resource(void* arg) {
    int thread_num = *(int*)arg;

    printf("Thread %d: Waiting to access resource...\n", thread_num);

    // Wait (decrement) on semaphore
    sem_wait(&semaphore);

    // Critical section
    printf("Thread %d: Entered critical section.\n", thread_num);
    sleep(2);  // Simulate resource usage
    printf("Thread %d: Leaving critical section.\n", thread_num);

    // Signal (increment) on semaphore
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int t1 = 1, t2 = 2;

    // Initialize semaphore to allow only one thread in the critical section at a time
    sem_init(&semaphore, 0, 1);

    // Create threads
    pthread_create(&thread1, NULL, access_resource, &t1);
    pthread_create(&thread2, NULL, access_resource, &t2);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

