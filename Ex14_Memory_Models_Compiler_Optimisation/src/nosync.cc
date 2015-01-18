#include <cstdio>
#include <pthread.h>
#include <unistd.h>

volatile int counter = 0;
pthread_mutex_t myMutex;

void* mutex_testing(int* param) {
  int i;
  for (i = 0; i < 5; i++) {
    counter++;
    usleep(1); // simulate some process
    printf("thread %d counter = %d\n", (int)param, counter);
  }
}

int main() {
  int one = 1, two = 2, three = 3;
  pthread_t thread1, thread2, thread3;
  pthread_create(&thread1, 0, mutex_testing, (void*)one);
  pthread_create(&thread2, 0, mutex_testing, (void*)two);
  pthread_create(&thread3, 0, mutex_testing, (void*)three);
  pthread_join(thread1, 0);
  pthread_join(thread2, 0);
  pthread_join(thread3, 0);
}
