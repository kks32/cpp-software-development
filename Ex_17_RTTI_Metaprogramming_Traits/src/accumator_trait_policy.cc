#include <iostream>

// Trait
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


// Summation
class SumPolicy {
 public:
  template <typename T1, typename T2>
  static void accumulate(T1& total, T2 const& value) {
    total += value;
  }
};

// Multiplication
class MultPolicy {
 public:
  template <typename T1, typename T2>
  static void accumulate(T1& total, T2 const& value) {
    total *= value;
  }
};



// Accumulator
template <typename T, typename Policy = SumPolicy,
          typename Traits = AccumulationTraits<T> >
class Accum {
 public:
  typedef typename Traits::AccT AccT;
  static AccT accum(T const* beg, T const* end) {
    AccT total = Traits::zero;
    while (beg != end) {
      Policy::accumulate(total, *beg);
      ++beg;
    }
    return total;
  }
};
int main() {
  // create array of 5 integer values
  int num[] = {1, 2, 3, 4, 5};

  // print product of all values
  std::cout << "the product of the integer values is "
            << Accum<int, SumPolicy>::accum(&num[0], &num[5]) << '\n';
}
