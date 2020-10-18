#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int fd, retval;
    fd = open("/tmp/myfifo", O_WRONLY);

    while(1) {
        char buffer[100];
        printf("Write something (exit to quit): ");
        fgets(buffer, 100, stdin);
        fflush(stdin);
        retval = mkfifo("/tmp/myfifo", 0666);
        write(fd, buffer, sizeof(buffer));

        if (strcmp(buffer, "exit") == 0){
            break;
        }
    }
    close(fd);
    return 0;
}