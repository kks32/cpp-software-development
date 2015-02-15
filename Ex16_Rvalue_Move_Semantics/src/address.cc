#include <iostream>

struct Object {
  int x;
  int getInt() { return x; }

  int&& getRvalueInt() { return std::move(x); }
};

void printAddress(const int& v) {  // const ref to allow binding to rvalues
  std::cout << reinterpret_cast<const void*>(&v) << std::endl;
}

int main() {
  Object obj;
  std::cout << "Address of getint    :";
  printAddress(obj.getInt());
  std::cout << "Address of object `x':";
  printAddress(obj.x);

  // On the other hand,

  std::cout << "Address of rvalueint :";
  printAddress(obj.getRvalueInt());
  std::cout << "Address of object `x':";
  printAddress(obj.x);
}
