#include <pthread.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#define ITERATIONS 100000000
volatile int A;
uint64_t __padding__[16]; //padding to operate on diff lines
int B;
static void * thread_func(void *){
        for (int i = 0; i < ITERATIONS; i++){
                if (A == 1) {
                        A = 0;
			system("flush.sh");
                } else {
                        A = 1;
			system("flush.sh");
                }
        }
}

int main() {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, NULL);
        return 0;
}
