#include <pthread.h>
#include <stdio.h>

#define ITERATIONS 100000000
volatile int A;

static void * thread_func(void *){
        for (int i = 0; i < ITERATIONS; i++){
                if (A == 1) {
                        A = 0;
                } else {
                        A = 1;
                }
        }
}
int main() {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, NULL);
        return 0;
}
