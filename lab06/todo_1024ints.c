#include <stdio.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    int N = 1024;
    int *ptr = mmap ( NULL, N*sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );

    if(ptr == MAP_FAILED){
        printf("Mapping Failed\n");
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        ptr[i] = i;
    }

    printf("These are the %d integers\n", N);
    for (int i = 0; i < N; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    if (munmap(ptr, N*sizeof(int))) {
        printf("Unmapping failed\n");
    } else {
        printf("Unmapping was successful\n");
    }

    return 0;
}