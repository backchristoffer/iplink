#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int iplink() {
    int r=system("ip -s link");   
    return r;
}

int main(void)
{   
    iplink();
    return 0;
}