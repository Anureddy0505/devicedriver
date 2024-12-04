#include <stdio.h>

extern void global_function();  // Declaration of global_function from file1.c

int main() {
    global_function();
    // static_function();  // Uncommenting this will cause a linker error
    return 0;
}
