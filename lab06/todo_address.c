#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    int *p1;
    int *p2; 
    p1 = malloc(sizeof(int));
    p2 = malloc(sizeof(int));
    assert(p1 != NULL && p2 != NULL);
    *p1 = 23;
    *p2 = 45;

    printf("First number is %d\n", *p1);
    printf("Guess for the second number is %d\n", *(p1 + 1));
    printf("Second number is %d\n", *p2);
    return 0;
}