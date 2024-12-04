#include <pthread.h>
#include <stdio.h>

int main() {
    pthread_attr_t attr;
    size_t stacksize;

    // Initialize thread attributes
    pthread_attr_init(&attr);

    // Get the stack size attribute
    pthread_attr_getstacksize(&attr, &stacksize);

    // Print stack size
    printf("Default stack size: %zu bytes\n", stacksize);

    // Destroy the attributes object
    pthread_attr_destroy(&attr);

    return 0;
}

