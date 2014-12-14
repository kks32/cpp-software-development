#include <thread>
#include <iostream>
#include <vector>

class Counter {
  int value_;

 public:

  Counter() : value_(0){}

  void increment() { ++value_; }
  int value() { return value_; }
  void value(int& newvalue) { value_ = newvalue; }
};

int main() {
  Counter counter;

  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.push_back(std::thread([&counter]() {
      for (int i = 0; i < 100; ++i) {
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
