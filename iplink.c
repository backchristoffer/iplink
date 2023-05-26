#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{   
    int r;
    r=system("ip -s link");
    printf("%d\n",r);
    pause();
    return 0;
}