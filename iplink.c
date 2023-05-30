#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void timestamp()
{
    time_t ltime;
    ltime=time(NULL);
    printf("%s",asctime(localtime(&ltime)) );
}

int iplink() {
    timestamp();
    int r=system("ip -s link");   
    return r;
}

int main(void)
{   
    while (1) {
        iplink();
        sleep(30);
    }
    return 0;
}