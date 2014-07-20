#ifndef CPPFACTORY_DERIVEDCLASSTWO_H
#define CPPFACTORY_DERIVEDCLASSTWO_H

#include "MyBaseClass.h"
#include <iostream>
using namespace std;

class DerivedClassTwo : public MyBaseClass
{
public:    
    DerivedClassTwo(){};
    virtual ~DerivedClassTwo(){};

    virtual void doSomething() { cout << "I am class two" << endl; }
};
#endif // CPPFACTORY_DERIVEDCLASSTWO_H