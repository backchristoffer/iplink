#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{   
    int r;
    int i;
    r=system("ip -s link");
    i=system("ip a");
    printf("%d\n",r);
    printf("%d\n",i);
    pause();
    return 0;
}