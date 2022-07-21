#include <pthread.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

int values = 10;

void *print_value(void *arguments) {
    printf("values = %d\n", values);
    values = 12;
    return NULL;
}

int main() {
    pthread_t a, b;

    int ret = pthread_create(&a, NULL, print_value, NULL);

    sleep(3);

    ret = pthread_create(&b, NULL, print_value, NULL);

    pthread_join(a, NULL);
    pthread_join(b, NULL);

    return 0;
}