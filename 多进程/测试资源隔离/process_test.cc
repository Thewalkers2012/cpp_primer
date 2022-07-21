#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int values = 10;

int main() {
    pid_t pid = fork();
    assert(pid >= 0);
    if (pid == 0) {
        printf("father values %d\n", values);
        printf("father values address: %p\n", &values);
        values = 12;
        printf("changed values = %d\n", values);
    } else {
        sleep(5);
        printf("child values = %d\n", values);
        printf("clild values address: %p\n", &values);
    } 
    sleep(10);
}