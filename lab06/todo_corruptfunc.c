#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int corruptfunc(int a) {
    int v = a;
    void *addr = __builtin_extract_return_addr (__builtin_return_address (0));
    return v;
}

int main(int argc, char *argv[]) {
    int i = 3;
    int returned_value = corruptfunc(i);

    printf("Returned value is %d\n", returned_value);
    
    if (returned_value == i) {
        printf("Returned value was not corrupted\n");
    } else {
        printf("Returned value was corrupted\n");
    }
    return 0;
}