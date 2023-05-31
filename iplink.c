#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _)
{
    (void)_;
    keep_running = 0;
}

void timestamp() {
    time_t t;
    time(&t);
    printf("%s\n",ctime(&t));
    fflush(stdout);
}

void* iplink( void * arg) {
    int r=system("ip -s link");
    return NULL;
}

int main(void)
{   
    pthread_t tsthread;
    signal(SIGINT, sig_handler);

    while (keep_running) {
        timestamp();
        pthread_create(&tsthread, NULL, iplink, NULL);
        sleep(15);
    }

    return EXIT_SUCCESS;
}