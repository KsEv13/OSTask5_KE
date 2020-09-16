#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* show(void *args) {
    int id = *(int *) args;
    printf("Text from thread # %d\n", id);
}

int main() {
    pthread_t tid;
    for (int i = 0; i < 3; ++i){
        void *pointer = &i;
        pthread_create(&tid, NULL, &show, &i);
        printf("Thread #%d was created \n", i);
        pthread_join(tid, NULL); //prevents from unordered output
    }
    pthread_exit(NULL);
    return 0;
}

