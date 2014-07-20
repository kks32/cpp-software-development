#ifndef CPPFACTORY_DERIVEDCLASSONE_H
#define CPPFACTORY_DERIVEDCLASSONE_H

#include "MyBaseClass.h"
#include <iostream>
using namespace std;

class DerivedClassOne : public MyBaseClass
{
public:
    DerivedClassOne(){};
    virtual ~DerivedClassOne(){};

    virtual void doSomething() { cout << "I am class one" << endl; }
};
#endif // CPPFACTORY_DERIVEDCLASSONE_H