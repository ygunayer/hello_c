#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long fib(unsigned long n) {
    if (n <= 2) {
        return 1;
    }

    return fib(n - 2) + fib(n - 1);
}

int main() {
    unsigned int size = 65;
    char* buf = malloc(sizeof(char) * size);

    if (buf == NULL) {
        fprintf(stderr, "Failed to allocate memory of size %u: %s", size, strerror(errno));
        return -1;
    }

    printf("Please enter a number: ");

    if (fgets(buf, size, stdin) == NULL) {
        free(buf);
        fprintf(stderr, "Failed to read from stdin");
        return -1;
    }

    unsigned long limit;
    if (sscanf(buf, "%u", &limit) != 1) {
        free(buf);
        fprintf(stderr, "Failed to parse input as number");
        return -1;
    }

    free(buf);

    unsigned long result = fib(limit);
    printf("fib(%u) = %u", limit, result);
    return 0;
}
