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

template <typename T, typename AT = AccumulationTraits<T> >
class Accum {
 public:
  static typename AT::AccT accum(T const* beg, T const* end) {
    typename AT::AccT total = AT::zero;
    while (beg != end) {
      total += *beg;
      ++beg;
    }
    return total;
  }
};

int main() {
  // create array of 5 integer values
  int num[] = {1, 2, 3, 4, 5};
  // print average value
  std::cout << "the average value of the integer values is "
            << Accum<int, AccumulationTraits<int> >::accum(&num[0], &num[5]) / 5
            << std::endl;

  // create array of character values
  char name[] = "templates";
  int length = sizeof(name) - 1;
  std::cout << "the average value of the characters in" << name << " is "
            << Accum<char>::accum(&name[0], &name[length]) / length
            << std::endl;
}
