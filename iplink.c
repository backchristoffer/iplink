#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{   
    int r;
    int i;
    r=system("ip -s link");
    i=system("ip a");
    printf("%d\n",r);
    printf("%d\n",i);
    sleep(120);
    return 0;
}