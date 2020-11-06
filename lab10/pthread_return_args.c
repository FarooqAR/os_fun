#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

static void * thread_func(void * arg) {
    char *s = (char *) arg;
    return (void *) strlen(s);
}

int main(int argc, char *argv[]) {
    pthread_t t1;
    void * res;
    int s;

    s = pthread_create(&t1, NULL, thread_func, "HelloWorld\n");
    if (s != 0) {
        perror("error: pthread_create");
        exit(EXIT_FAILURE);
    }
    printf("Message from main\n");

    s = pthread_join(t1, &res);

    if (s != 0) {
        perror("error: pthread_join");
        exit(EXIT_FAILURE);
    }
    printf("Thread returned %ld\n", (long) res);
    exit(EXIT_SUCCESS);
}