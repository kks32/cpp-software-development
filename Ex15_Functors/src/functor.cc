#include <iostream>
#include <algorithm>
#include <vector>

// this is a functor
class Multiplier {
  double x_;

public:
  Multiplier(double x) : x_{x} {}
  double operator()(double y) { return x_ * y; }
};

int main() {
  Multiplier doubler{2};
  double x = 20;
  std::cout << "Value " << x << " doubled is: " << doubler(x) << std::endl;


  std::vector<int> in{1, 2, 3, 4, 5};
  std::vector<int> out;
  out.resize(in.size());

  // Pass a functor to std::transform, which calls the functor on every element
  // in the input sequence, and stores the result to the output sequence

  for (auto& elout : in) std::cout << "Original Value :" << elout << std::endl;

  std::transform(in.begin(), in.end(), out.begin(), Multiplier(5));

  for (auto& elout : out) std::cout << "Modified Value :" << elout << std::endl;
}
