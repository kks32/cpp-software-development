#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

class Counter {
  int value_;
  std::mutex mutex;
  void cincrement() {  ++value_; }
  void cdecrement() {
    if(value_ == 0) {
      throw "Value cannot be less than 0";
    }
    --value_;
  }

 public:

  Counter() : value_(10){}


  void increment() {
    mutex.lock();
    cincrement();
    mutex.unlock();
  }

  void decrement() {
    mutex.lock();
    try {
      cdecrement();
    } catch (std::string e){
      mutex.unlock();
      throw e;
    }
    mutex.unlock();
  }
  int value() { return value_; }
  void value(int& newvalue) { value_ = newvalue; }
};

int main() {
  Counter counter;

  std::cout << counter.value() << std::endl;

  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.push_back(std::thread([&counter]() {
        counter.decrement();
        printf("%d \n", counter.value());
    }));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  counter.increment();
  std::cout << "After 1 increment: " << counter.value() << std::endl;
}
