#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes for operations
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
int mod(int, int);

// Enum to represent operations
enum fun { Add, Sub, Mul, Div, Mod };

// Structure containing an array of function pointers
typedef struct {
    int (*fp[5])(int, int); // Array of 5 function pointers
} st;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <operation> <num1> <num2>\n", argv[0]);
        return 1;
    }

    st stu;
    enum fun f;
    int index = -1; // Default invalid index
    int res;

    // Initialize the function pointer array
    stu.fp[Add] = add;
    stu.fp[Sub] = sub;
    stu.fp[Mul] = mul;
    stu.fp[Div] = div;
    stu.fp[Mod] = mod;

    char *ch = argv[1];   // Operation (string)
    int a = atoi(argv[2]); // First operand
    int b = atoi(argv[3]); // Second operand

    // Determine the operation based on the input string
    if (strcmp(ch, "add") == 0) {
        index = Add;
    } else if (strcmp(ch, "sub") == 0) {
        index = Sub;
    } else if (strcmp(ch, "mul") == 0) {
        index = Mul;
    } else if (strcmp(ch, "div") == 0) {
        index = Div;
    } else if (strcmp(ch, "mod") == 0) {
        index = Mod;
    } else {
        printf("Invalid operation. Use one of: add, sub, mul, div, mod\n");
        return 1;
    }

    // Call the corresponding function using the function pointer
    if (index >= 0 && index <= 4) {
        res = stu.fp[index](a, b);
        printf("Result: %d\n", res);
    } else {
        printf("Invalid operation index.\n");
    }

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int mod(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

