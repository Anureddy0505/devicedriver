#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_var = 10;  // Global variable shared between parent and child

int main() {
    printf("Before vfork, global_var = %d\n", global_var);
	int a=10;
    pid_t pid = vfork();
    if (pid < 0) {
        // Error handling if vfork() fails
        perror("vfork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        global_var += 5;  // Modify the global variable
		a=100;
        printf("In child process, global_var = %d %d\n", global_var,a);
       //exit(0);  // Ensure the child process exits without returning to main()
    } else {
        // Parent process resumes here after the child exits
        printf("In parent process, global_var = %d %d\n", global_var,a);
    }

    return 0;
}

