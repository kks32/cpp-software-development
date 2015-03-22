#include <iostream>

template <typename T>
T accum(T const* beg, T const* end) {
  T total = T();  // assume T() actually creates a zero value
  while (beg != end) {
    total += *beg;
    ++beg;
  }
  return total;
}

int main() {
  // create array of 5 integer values
  int num[] = {1, 2, 3, 4, 5};
  // print average value
  std::cout << "the average value of the integer values is "
            << accum(&num[0], &num[5]) / 5 << '\n';

  // create array of character values
  char name[] = "templates";
  int length = sizeof(name) - 1;
  std::cout << "the average value of the characters in" << name << " is "
            << accum(&name[0], &name[length]) / length << '\n';
}
