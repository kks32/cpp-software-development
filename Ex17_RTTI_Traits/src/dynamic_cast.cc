#include <iostream>
struct BaseA {
  virtual void print() { std::cout << "Base Class A" << std::endl; }
};

struct DerivedB : BaseA {

  virtual void print() { std::cout << "Derived Class B" << std::endl; }
};

struct DerivedC : BaseA {

  virtual void print() { std::cout << "Derived Class C" << std::endl; }
};

void dynamic_cast_function(BaseA* arg) {

  DerivedB* bp = dynamic_cast<DerivedB*>(arg);

  DerivedC* cp = dynamic_cast<DerivedC*>(arg);

  if (bp)
    bp->print();

  else if (cp)
    cp->print();

  else
    arg->print();
};

int main() {

  BaseA aobj;

  DerivedC cobj;

  BaseA* ptr = &aobj;

  BaseA* ptr2 = &cobj;  // BaseA* ptr

  // auto* ptr2 = &cobj; //BaseA* ptr

  // decltype(ptr) ptr2 = &cobj; //BaseA* ptr

  dynamic_cast_function(ptr);

  dynamic_cast_function(ptr2);
}
