#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

void * hello_fun(){
    printf("HelloWorld\n");
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);
    pthread_join(thread, NULL);
    return 0;
}