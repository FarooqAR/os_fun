// using locks increase the time by 3-4 times (as compared to not using any locks) on my machine!
// correctness comes with cost!
// locks increase contention time i.e a thread has to wait before it can access the code locked by another thread.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

#define INC_SIZE 10000000

static volatile int glob = 0;

static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void * access_global(void * args) {
    char * p = (char *) args;
    int loc = 0;

    printf("%s: thread started\n", p);

    for(int i = 0; i< INC_SIZE; i++) {
        pthread_mutex_lock(&m);
        loc = glob;
        loc++;
        glob = loc;
        pthread_mutex_unlock(&m);
    }

    printf("%s: thread ending\n", p);
    return NULL;
}

int main(int argc, char * argv[]) {
    pthread_t t1, t2;
    clock_t t;
    t = clock();
    printf("main: creating threads\n");
    pthread_create(&t1, NULL, access_global, "T0");
    pthread_create(&t2, NULL, access_global, "T1");
    printf("main: created threads\n");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("main: joined threads\n");
    printf("main: glob = %d\n", glob);

    t = clock() - t;
    double time_taken = ((double) t) / CLOCKS_PER_SEC;
    printf("total time: %f\n", time_taken);
    return 0;
}