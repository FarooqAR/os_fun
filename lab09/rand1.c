#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 16

void die(char *str) {
    perror(str);
    exit(1);
}

int main(void) {
    int shmid;
    key_t key;
    int *shm;
    char s[1];

    key = 2211;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    
    if((shm = shmat(shmid, NULL, 0)) == (int *) -1)
        die("shmat");
    

    srand ( time ( NULL));

    while (1) {
        *shm = rand() % 100;
        printf("%d\n", *shm);
        sleep(5);
    }

    exit(0);
}