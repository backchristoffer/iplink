#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include  <signal.h>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _)
{
    (void)_;
    keep_running = 0;
}

int iplink() {
    int r=system("ip -s link");   
    return r;
}

int main(void)
{   
    time_t ltime;
    ltime=time(NULL);
    signal(SIGINT, sig_handler);

    while (keep_running) {
        printf("%s",asctime(localtime(&ltime)) );
        iplink();
        sleep(30);
    }
    return EXIT_SUCCESS;
}