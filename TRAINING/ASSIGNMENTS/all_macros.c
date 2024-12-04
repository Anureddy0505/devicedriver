#include <stdio.h>
#include<stdlib.h>
void example_function() {
    printf("Function: %s\n", __func__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
}

int main() {
    example_function();
    return 0;
}
