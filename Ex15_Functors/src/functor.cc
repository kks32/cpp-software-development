#include <iostream>

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
}
