#include <stdio.h>

int main(int argc, char *argv[])
{
    int t;
    sscanf(argv[1], "%d", &t);
    if(argc == 2){
        printf("t = %d\n", t);
    }

    return 0;
}