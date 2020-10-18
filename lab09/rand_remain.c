#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 16

void die(char * str) {
    perror(str);
    exit(1);
}

int main(void) {
    int shmid_a;
    int shmid_b;
    key_t key_a;
    key_t key_b;
    int *shm_a;
    double *shm_b;

    key_a = 2211;
    key_b = 2212;
    fflush(stdin);
    
    if ((shmid_a = shmget(key_a, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if((shm_a = shmat(shmid_a, NULL, 0)) == (int * ) -1)
        die("shmat");
    
    if ((shmid_b = shmget(key_b, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    if(*(shm_b = shmat(shmid_b, NULL, 0)) == -1.0)
        die("shmat");

    while(1) {
        printf("%.2f", fmod((double) *shm_a, *shm_b)); // by remainder I assume it's the remainder we get when dividing rand1 by rand2
        sleep(10);
    }

    printf("\n");
    exit(0);
}