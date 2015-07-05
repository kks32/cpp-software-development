#include <iostream>
int main() {
  int&& x = int();
  x = 3;
  std::cout << x << std::endl;
}
