// hello_pthread.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

void * hello_fun(void * args) {
    printf("Hello World\n");
    return NULL;
}

int main(int argc, char * argv[]){
    pthread_t t0, t1; // thread identifier

    pthread_create(&t0, NULL, hello_fun, NULL);
    pthread_create(&t1, NULL, hello_fun, NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    return 0;
}