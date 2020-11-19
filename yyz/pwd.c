#include <stdio.h>
#include <unistd.h>
#define MAXPATH 50

int main()
{
    char path[MAXPATH];
    puts(getcwd(path, MAXPATH));
    return 0;
}
