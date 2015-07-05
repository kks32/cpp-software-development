#include <iostream>
int main() {
  char* ptr;
  char str[] = "abcdefg";
  ptr = str;
  ptr += 5;
  std::cout << ptr << std::endl;
}
