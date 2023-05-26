#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{   
    int r;
    int i;
    
    r=system("ip -s link");
    i=system("ip a");

    printf(system("ip -s link"));
    printf(system("ip a"));
    
    sleep(120);
    
    return 0;
}