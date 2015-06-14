// Determine what's the output

#include <iostream>
#include <typeinfo>

class Base {
 public:
  Base() {}
  ~Base() { std::cout << "Base class destructor called" << std::endl; }
  virtual void foo(int i = 10) {
    std::cout << "Base class foo called with i: " << i << std::endl;
  }
};

class Derived : public Base {
 public:
  Derived() {}
  ~Derived() { std::cout << "Derived class destructor called" << std::endl; }
  virtual void foo(int k = 5) {
    std::cout << "Derived class foo called with k: " << k << std::endl;
  }
};

int main() {
  Base* bptr = new Derived(); // Convert to Derived ptr and see

  std::cout << "Type id: " << typeid(*bptr).name() << std::endl;

  bptr->foo(); // Pass an integer and check.

  delete bptr;
}
