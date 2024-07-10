#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define MAX_SIZE 10

int buffer[BUFFER_SIZE];
int rear = 0;
int front = 0;
int produced = 0;
int consumed = 0;

sem_t mutex;
sem_t full;
sem_t empty;


void * prod(void * arg) {
  int item = 1;
  while(produced < MAX_SIZE) {
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[rear] = item;
    printf("produced %d item\n", item);
    item++;
    rear = (rear + 1) % BUFFER_SIZE;
    produced++;
    sem_post(&mutex);
    sem_post(&full);
  }
  pthread_exit(NULL);
}

void * cons(void * arg) {
  int item;
  while(consumed < MAX_SIZE) {
    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[front];
    printf("consumed %d item\n", item);
    front = (front + 1) % BUFFER_SIZE;
    consumed++;
    sem_post(&mutex);
    sem_post(&empty);
  }
  pthread_exit(NULL);
}

void main() {
  pthread_t pt, ct;
  sem_init(&mutex, 0, 1);
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);

  pthread_create(&pt, NULL, prod, NULL);
  pthread_create(&ct, NULL, cons, NULL);

  pthread_join(pt, NULL);
  pthread_join(ct, NULL);

  sem_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
}
