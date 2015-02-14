// This is an example with default copy constructor
#include <iostream>
#include <string>

class Widget {
  int x = 10;
  int* ptr;

 public:
  Widget() { ptr = &x; };
  int xvalue() { return *ptr; };
  void xvalue(const int newx) { x = newx; };
};

int main() {
  Widget w1;
  std::cout << "Widget W1 has a value of : " << w1.xvalue() << std::endl;

  Widget w2{w1};  // default copy constructor is called
  // Widget w2 = w1; // default assignment operator

  std::cout << "Widget W2 has a value of : " << w2.xvalue() << std::endl;

  w1.xvalue(5);  // Value of w1.x is changed to 5
  std::cout << "Widget W1 has a value of : " << w1.xvalue() << std::endl;
  std::cout << "Widget W2 has a value of : " << w2.xvalue() << std::endl;
}
