#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS 100000

int counter = 0; // Shared resource
pthread_mutex_t counter_mutex; // Mutex to protect the counter

// Function to increment the counter
void* increment_counter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Lock the mutex before modifying the counter
      pthread_mutex_lock(&counter_mutex);

        counter++;
        // Unlock the mutex after modifying the counter
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&counter_mutex, NULL);

    // Create two threads that run increment_counter
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&counter_mutex);

    // Print the result
    printf("Final counter value: %d\n", counter); // Should be 2,000,000

    return 0;
}

