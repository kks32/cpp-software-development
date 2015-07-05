#include <iostream>
template <int i>
void fun() {
  i = 20;
  std::cout << i << std::endl;
}
int main() { fun<10>(); }
