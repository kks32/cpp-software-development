#include <iostream>

int& fun() {
  static int x = 10;  // Remove static and see what the result is
  return x;
}
int main() {
  fun() = 30;
  std::cout << fun() << std::endl;
}
