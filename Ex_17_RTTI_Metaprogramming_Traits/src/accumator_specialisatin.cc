#include <iostream>

template <typename T>
class AccumulationTraits;

template <>
class AccumulationTraits<char> {
 public:
  typedef int AccT;
  static AccT const zero = 0;
};

template <>
class AccumulationTraits<int> {
 public:
  typedef int AccT;
  static AccT const zero = 0;
};

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const* beg, T const* end) {
  // return type is traits of the element type
  typedef typename AccumulationTraits<T>::AccT AccT;

  AccT total = AccumulationTraits<T>::zero;
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
            << accum<int>(&num[0], &num[5]) / 5 << std::endl;

  // create array of character values
  char name[] = "templates";
  int length = sizeof(name) - 1;
  std::cout << "the average value of the characters in" << name << " is "
            << accum<char>(&name[0], &name[length]) / length << std::endl;
}
