#ifndef CPPFACTORY_DERIVEDCLASSTWO_H
#define CPPFACTORY_DERIVEDCLASSTWO_H

#include "MyBaseClass.h"
#include <iostream>

class DerivedClassTwo : public MyBaseClass
{
public:    
    DerivedClassTwo(){};
    virtual ~DerivedClassTwo(){};

    virtual void info() {
        std::cout << "Java course" << std::endl; 
    }
};
#endif // CPPFACTORY_DERIVEDCLASSTWO_H
