#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 5

#define PRODUCERS 5
#define CONSUMERS 5

int buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t full, empty;

int count, produceIndex, consumeIndex;

bool insertItem(int item) {

  bool success = false;

  sem_wait(&empty);
  pthread_mutex_lock(&mutex);

  if (count != BUFFER_SIZE) {
    buffer[produceIndex] = item;
    produceIndex = (produceIndex + 1) % BUFFER_SIZE;
    count++;
    success = true;
  }

  pthread_mutex_unlock(&mutex);
  sem_post(&full);

  return success;
}

bool removeItem(int *item) {

  bool success = false;

  sem_wait(&full);
  pthread_mutex_lock(&mutex);

  if (count != 0) {
    *item = buffer[consumeIndex];
    consumeIndex = (consumeIndex + 1) % BUFFER_SIZE;
    count--;
    success = true;
  }

  pthread_mutex_unlock(&mutex);
  sem_post(&empty);

  return success;
}

void *producer() {

  while (true) {

    sleep(rand() % 5 + 1);

    int item = rand() % 10;
    // int item = rand() % 10;

    if (!insertItem(item))
      printf("Error\n");
    else
      printf("Producer Produced: %d\n", item);
  }
}

void *consumer(void *param) {

  int item;

  while (true) {

    sleep(rand() % 5 + 1);

    if (!removeItem(&item))
      printf("Error\n");
    else
      printf("Consumer Consumed: %d\n", item);
  }
}

int main() {

  srand(time(NULL));

  pthread_mutex_init(&mutex, NULL);

  sem_init(&empty, 0, BUFFER_SIZE);

  sem_init(&full, 0, 0);

  count = produceIndex = consumeIndex = 0;

  pthread_t producers[PRODUCERS];
  pthread_t consumers[CONSUMERS];

  for (int i = 0; i < PRODUCERS; i++)
    pthread_create(&producers[i], NULL, producer, NULL);

  for (int i = 0; i < CONSUMERS; i++)
    pthread_create(&consumers[i], NULL, consumer, NULL);

  for (int i = 0; i < PRODUCERS; i++)
    pthread_join(producers[i], NULL);

  for (int i = 0; i < CONSUMERS; i++)
    pthread_join(consumers[i], NULL);

  return 0;
}