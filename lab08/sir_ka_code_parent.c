//Parent.c
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd, retval;
    char msg[100] = {'\0'};

    retval = mkfifo("/tmp/myfifo", 0666);
    fd = open("/tmp/myfifo", O_WRONLY);

    puts("Enter your message (QUIT to terminate): ");
    fflush(stdin);
    fgets(msg, 100, stdin);
   
    while (1)
    {
        int size = strlen(msg);
        write(fd, msg, size);

        puts("Enter your message (QUIT to terminate): "); 
        fflush(stdin);
        fgets(msg, 100, stdin);
        

        if(strncmp(msg, "QUIT", 4)== 0)
            break;
    }
    close(fd);

    return 0;
}
