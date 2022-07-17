#include <stdio.h>
#include <stdint.h>

#include <poboy.h>

struct poboy ctx = { 0 };

int main(void) {
    printf("Hello, World! %p (%zu)\n", (void*)&ctx, sizeof(ctx));
    return 0;
}

