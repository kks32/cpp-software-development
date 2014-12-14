#include <thread>
#include <iostream>
#include <vector>
#include <cstdlib>

static const int num_threads = 10;

// This function will be called from a thread
void hello_id(int id) {
  std::cout << std::this_thread::get_id() << std::endl;

}

int main() {
  std::vector<std::thread> threads;
  // Launch a group of threads
  for (int i = 0; i < num_threads; ++i) {
    threads.push_back(std::thread(hello_id, i));
  }

  // Join the threads with the main thread
  for (auto& thread : threads) {
    thread.join();
  }
}
