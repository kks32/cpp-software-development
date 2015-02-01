#include <iostream>

class f {
  int retval;  // f's "return value"
  int j;
  int g(int k) { return j + k; };

 public:
  f(int i) : j(i * 2) {  // original function, now a constructor
    j += 4;
    retval = g(3);
  }
  operator int() const {  // returning the result
    return retval;
  }
};

int main() { std::cout << "Value of f(5) is : " << f(5) << std::endl; }
