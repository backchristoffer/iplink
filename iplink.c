#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int r;
    int i = 0;
    r=system("ip -s link");
    while (i <= 5) {
        printf("%d\n",r);
        ++i;
    }
    return 0;
}