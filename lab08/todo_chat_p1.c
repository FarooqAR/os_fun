#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int pid = fork();

    if (pid > 0) {
        int fd = open("/tmp/myfifo1", O_WRONLY);
        // while(1) {
            
            char buffer[100];
            printf("Write something: ");
            scanf("%[^\n]%*c", buffer);
            fflush(stdin);
            int retval = mkfifo("/tmp/myfifo1", 0666);
            write(fd, buffer, sizeof(buffer));
            
            if (strcmp(buffer, "exit") == 0){
                break;
            }
        // }
        close(fd);
    } else {
        int fd = open("/tmp/myfifo2", O_RDONLY);
        while(1) {
            char buffer[100];
            int retval = read(fd, buffer, sizeof(buffer));
            fflush(stdin);
            printf("\nIncoming message from P2: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0){
                printf("P2 left the chat!\n");
                break;
            }
        }
        close(fd);
    }
    
    return 0;
}