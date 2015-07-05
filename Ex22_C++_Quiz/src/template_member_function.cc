#include <iostream>
struct Base {
  int x;
  template <int Trange>
  void print() {
    std::cout << "Base class : " << Trange + x + 1 << std::endl;
  }
};
struct Derived : public Base {
  template <int Trange>
  void print() {
    std::cout << "Derived class : " << Trange + x + 2 << std::endl;
  }
};
int main() {
  Base* p = new Derived;
  p->x = 1;
  p->print<5>();
}
