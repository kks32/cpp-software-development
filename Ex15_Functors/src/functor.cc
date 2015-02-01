#include <iostream>
#include <algorithm>

// this is a functor
class Multiplier {
  double x;

 public:
  Multiplier(double x) : x{x} {}
  double operator()(double y) { return x * y; }
};

int main() {
  Multiplier doubler{2};
  double x = 20;
  std::cout << "Value " << x << " doubled is: " << doubler(x) << std::endl;


  std::vector<int> in{1, 2, 3, 4, 5};

  // Pass a functor to std::transform, which calls the functor on every element
  // in the input sequence, and stores the result to the output sequence

  for (auto& elout : in) std::cout << "Original Value :" << elout << std::endl;

  std::transform(in.begin(), in.end(), in.begin(), Multiplier(5));

  for (auto& elout : in) std::cout << "Modified Value :" << elout << std::endl;
}
