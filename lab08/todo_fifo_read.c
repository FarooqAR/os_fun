#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int fd, retval;
    printf("Waiting for sender ...\n");
    fd = open("/tmp/myfifo", O_RDONLY);
    while(1) {
        char buffer[100];
        retval = read(fd, buffer, sizeof(buffer));
        fflush(stdin);
        printf("Incoming message from P1: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0){
            break;
        }
    }
    close(fd);
    return 0;
}