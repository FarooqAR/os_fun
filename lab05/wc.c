#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    printf("%s has run with %d additional arguments\n", argv[0], argc - 1);
    return 0;
}