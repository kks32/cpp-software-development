#include <iostream>
#include <thread>
#include <string>

void execute(const std::string& name) {
  std::cout << "Hello Concurent World, and hello " << name << std::endl;
}

int main() {
  std::string your_name = "Krishna!";
  std::thread worker_thread(execute, your_name);

  worker_thread.join();
}
