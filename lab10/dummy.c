#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    void *res;
    int s;

    int *a = malloc(100000000 * sizeof(int));
    if (a == NULL) {
        perror("error: memory failure");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i < 1000000000; i++)
        a[i%100000000] = 1000000000;

    free(a);
    exit(EXIT_SUCCESS);
}