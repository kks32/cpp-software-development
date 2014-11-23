#include <iostream>
#include <thread>
#include <cstdio>

static const int num_threads = 10;

//This function will be called from a thread
void call_from_thread(int tid) {
    printf("Launched by thread %d \n", tid);
}

int main() {
  std::thread t[num_threads];

  //Launch a group of threads
  for (int i = 0; i < num_threads; ++i) {
      t[i] = std::thread(call_from_thread, i);
  }

  printf("Launched from the main\n");

  //Join the threads with the main thread
  for (int i = 0; i < num_threads; ++i) {
      t[i].join();
  }

}
