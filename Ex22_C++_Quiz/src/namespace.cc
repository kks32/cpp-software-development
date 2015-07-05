#include <iostream>
namespace foo {
int x;
}
namespace foo {
void bar() {
  x++;
  std::cout << x << std::endl;
}
}
int main() {
  foo::x = 0;
  foo::bar();
}
