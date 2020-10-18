#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 16

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void die(char *str) {
    perror(str);
    exit(1);
}

int main(void) {
    int shmid;
    key_t key;
    double *shm;
    char s[1];

    key = 2212;

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
        die("shmget");
    
    if(*(shm = shmat(shmid, NULL, 0)) == -1.0)
        die("shmat");
    
    srand ( time ( NULL));

    while (1) {
        *shm = fRand(999.0, 10000.0);
        printf("%.2f\n", *shm);
        sleep(2);
    }
    exit(0);
}