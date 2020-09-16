#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define BUFF_SIZE 10

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
int buffer = 0;
int i = 1;

void *producer(void *ptr)
{
	
	while(1){
		//pthread_mutex_lock(&the_mutex);
		while(buffer == BUFF_SIZE) 
			pthread_cond_wait(&condp,&the_mutex);
		i = i + 1;
		buffer = i;
		printf("Producer produced item N=%d\n", i);
		pthread_cond_signal(&condc);
		//pthread_mutex_unlock(&the_mutex);
		
	}
	pthread_exit(0);
}

void *consumer(void *ptr)
{

	while(1){
		//pthread_mutex_lock(&the_mutex);
		while(buffer == 0) 
			pthread_cond_wait(&condc,&the_mutex);
		
		i = i - 1;
		buffer = i;
		printf("Consumer takes item N=%d\n",buffer);
		pthread_cond_signal(&condp);
		//pthread_mutex_unlock(&the_mutex);
		
	}
	pthread_exit(0);
}

int main(int argc, char **argv){ 
pthread_t pro, con; 
//pthread_mutex_init(&the_mutex, 0); 
pthread_cond_init(&condc, 0); 
pthread_cond_init(&condp, 0); 
pthread_create(&con, 0, consumer, 0);
pthread_create(&pro, 0, producer, 0); 
pthread_join(pro, 0);
pthread_join(con, 0); 
pthread_cond_destroy(&condc);

pthread_cond_destroy(&condp);
}
