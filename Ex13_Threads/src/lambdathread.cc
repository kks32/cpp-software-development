#include <thread>
#include <iostream>
#include <vector>
#include <cstdlib>

static const int num_threads = 2;

int main() {
  std::vector<std::thread> threads;
  // Launch a group of threads
  for (int i = 0; i < num_threads; ++i) {
    threads.push_back(std::thread([]() {
      std::cout << " Hello from thread " << std::this_thread::get_id()
                << std::endl;
    }));
  }

  // Join the threads with the main thread
  for (auto& thread : threads) {
    thread.join();
  }
}
