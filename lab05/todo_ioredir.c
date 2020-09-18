#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t i  = 0;
        char* token = strtok(a_str, delim);

        while (token != NULL)
        {
            *(result + i++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + i) = 0;
    }

    return result;
}

// returns -1 if output file is not given.
int output_filename_position(char ** tokens) {
    int i = 0;
    while (tokens[i] != NULL) {
        printf("%s\n", tokens[i]);
        if (strcmp(tokens[i], ">") == 0) {
            return i + 1;
        }
        i++;
    }
    return -1;
}

int
main(int argc, char *argv[])
{
    char line[100];
    printf("prompt> ");
    fgets(line, 100, stdin);
    line[strlen(line) - 1] = 0; // remove ENTER character
    while (strcmp(line, "exit") != 0) {
        char** myargs;
        myargs = str_split(line, ' ');
        int rc = fork();
        if (rc < 0) {
            // fork failed; exit
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc == 0) {
            // child (new process)
            int output_file_arg_pos = output_filename_position(myargs);
            printf("filepos %d\n", output_file_arg_pos);
            if (output_file_arg_pos > -1 && myargs[output_file_arg_pos] != NULL) {
                close(STDOUT_FILENO); 
                open(myargs[output_file_arg_pos], O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
            }
            printf("hello, I am child (pid:%d)\n", (int) getpid());
            execvp(myargs[0], myargs);
            exit(0);
        } else {
            // parent goes down this path (original process)
            int wc = wait(NULL);
            printf("hello, I am parent of %d (%s:%d) (pid:%d)\n",
            rc, myargs[0], wc, (int) getpid());
            printf("prompt> ");
            fgets(line, 100, stdin);
            line[strlen(line) - 1] = 0; // remove ENTER character
        }
    }

    return 0;
}