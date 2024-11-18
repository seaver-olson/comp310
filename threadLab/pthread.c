/*

Here is a program that calls pthread_create() to make one thread that will
print out a message. Your job is to modify this code to create five threads
that print out the message. Use a for loop to call pthread_create multiple
times, passing it a different parameter each time. Compile with:

gcc -o pthreadexample pthreadexample.c -pthread

*/


#include <stdio.h>
#include <pthread.h>

void print_hello(void *data) {
    printf("Hello from thread %d\n", (int)data);
}

int main() {
    pthread_t  thread_id;
    int k = 0;
    for (k; k < 5; k++) {
        pthread_create( &thread_id, NULL, print_hello, (void*)k);
    }
    pthread_exit(NULL);
    return 0;
}