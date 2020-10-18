//Child.c
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>

//child will just read and write data on screen
int main(void) {
	int fd, retval;
	char buffer[100] = {'\0'};
	
	fd = open("/tmp/myfifo",O_RDONLY);
    
	while(1)
    { 
	    retval = read(fd, buffer, sizeof(buffer)); 
		 
		printf("Parent says: %s", buffer); 
		
		if(strncmp(buffer, "QUIT", 4)==0)
			break;
    }	
	close(fd);
	return 0;
}
