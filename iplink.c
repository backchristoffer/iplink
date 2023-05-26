#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int r;
    r=system("ip -s link");
    return r;
}