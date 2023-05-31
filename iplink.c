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

void* timestamp( void * arg) {
    time_t t;
    time(&t);
    printf("%s",ctime(&t));
    return NULL;
}

void* iplink( void * arg) {
    int r=system("ip -s link");   
    return NULL;
}

int main(void)
{   
    pthread_t linkthread;
    pthread_t tsthread;
    signal(SIGINT, sig_handler);

    while (keep_running) {
        pthread_create(&linkthread, NULL, timestamp, NULL);
        pthread_create(&tsthread, NULL, iplink, NULL);
        sleep(30);
    }

    return EXIT_SUCCESS;
}