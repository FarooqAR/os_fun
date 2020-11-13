#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#define INC_SIZE 10000000

static volatile int glob = 0;

void * access_global(void * args) {
    char * p = (char *) args;
    int loc = 0;

    printf("%s: thread started\n", p);

    for(int i = 0; i< INC_SIZE; i++) {
        loc = glob;
        loc++;
        glob = loc;
    }

    printf("%s: thread ending\n", p);
    return NULL;
}

int main(int argc, char * argv[]) {
    pthread_t t1, t2;

    printf("main: creating threads\n");
    pthread_create(&t1, NULL, access_global, "T0");
    pthread_create(&t2, NULL, access_global, "T1");
    printf("main: created threads\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("main: joined threads\n");
    printf("main: glob = %d\n", glob);

    return 0;
}