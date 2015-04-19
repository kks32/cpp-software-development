#include <iostream>
// primary template to compute 3 to the Nth
template <int N>
class Pow3 {
 public:
  enum { result = 3 * Pow3<N - 1>::result };

  // Why not ? - No longer a pure compiler time 
  // static int const result = 3 * Pow3<N - 1>::result;
};

// full specialization to end the recursion
template <>
class Pow3<0> {
 public:
  enum { result = 1 };
};

int main() { std::cout << "Power 3^10 is : " << Pow3<2>::result << std::endl; }
