#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NULL_PTHREAD 0
#define MAX_BUFFER 1000000

int buffer=0;//buffer with data structures
int producer_enabled=1;
int consumer_enabled=0;
pthread_t thread_producer,thread_consumer;

void* producer(void *arg){
	int i=0;
	while(1){
		while(buffer==MAX_BUFFER);//Wait till buffer is not filled
		if(i%1000==0)
			printf("Producer %d %d\n",i,buffer);//Output the size of buffer and number of created data
		if(buffer<MAX_BUFFER){//Create data
			i++;
			buffer++;
		}
	}
}

void* consumer(void *arg){
	int i=0;
	while(1){
		while(buffer==0);//Wait till buffer is not empty
		if(i%1000==0)
			printf("Consumer %d %d\n",i,buffer);//Output the size of buffer and number of created data
		if(buffer>0){
			i++;
			buffer--;
		}
	}
}

//We don't use here any protection mechnisms.
//we can notice that sometimes output of a thread contains incorrect size of buffer, since the race condition happens: thread was
//blocked during the printf execution, but after activation, it still has the old value.

int main(){
	pthread_create(&thread_producer,NULL,&producer,NULL);
	pthread_create(&thread_consumer,NULL,&consumer,NULL);
	pthread_join(thread_producer,NULL);
	return 0;
}

