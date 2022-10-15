#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define N 5

#define EATING 0
#define HUNGRY 1
#define THINKING 2

#define LEFT (p + 4) % N
#define RIGHT (p + 1) % N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void test(int p) {

  if (state[p] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {

    state[p] = EATING;

    sleep(2);

    printf("P%d takes F%d and F%d\n", p, LEFT, p);

    printf("P%d is eating\n", p);

    sem_post(&S[p]);
  }
}

void takeFork(int p) {

  sem_wait(&mutex);

  state[p] = HUNGRY;

  printf("P%d is hungry\n", p);

  test(p);

  sem_post(&mutex);

  sem_wait(&S[p]);

  sleep(1);
}

void putFork(int p) {

  sem_wait(&mutex);

  state[p] = THINKING;

  printf("P%d puts F%d and F%d down\n", p, LEFT, p);
  printf("P%d is thinking\n", p);

  test(LEFT);
  test(RIGHT);

  sem_post(&mutex);
}

void *philosopher(void *p) {

  while (true) {

    int *i = p;

    sleep(1);

    takeFork(*i);

    sleep(0);

    putFork(*i);
  }
}

int main() {

  pthread_t thread_id[N];

  sem_init(&mutex, 0, 1);

  for (int i = 0; i < N; i++)
    sem_init(&S[i], 0, 0);

  for (int i = 0; i < N; i++) {

    pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);

    printf("P%d is thinking\n", i);
  }

  for (int i = 0; i < N; i++)
    pthread_join(thread_id[i], NULL);
}
