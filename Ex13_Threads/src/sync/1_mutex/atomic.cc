#include <thread>
#include <iostream>
#include <vector>
#include <atomic>

class Counter {
  std::atomic<int> value_;

 public:

  Counter() : value_(0){}

  void increment() {
      ++value_;
  }
  int value() { return value_; }
  void value(int& newvalue) { value_ = newvalue; }
};

int main() {
  Counter counter;

  std::vector<std::thread> threads;
  for (int i = 0; i < 500; ++i) {
    threads.push_back(std::thread([&counter]() {
      for (int i = 0; i < 1000; ++i) {
        counter.increment();
      }
    }));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  std::cout << counter.value() << std::endl;

  return 0;
}
