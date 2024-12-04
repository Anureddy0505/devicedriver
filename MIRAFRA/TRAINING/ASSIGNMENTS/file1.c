#include <stdio.h>

void global_function() {  // Default: external linkage
    printf("This is a global function.\n");
}

static void static_function() {  // Internal linkage
    printf("This is a static function.\n");
}
