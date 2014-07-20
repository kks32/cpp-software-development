#ifndef CPPFACTORY_DERIVEDCLASSONE_H
#define CPPFACTORY_DERIVEDCLASSONE_H

#include "MyBaseClass.h"
#include <iostream>

class DerivedClassOne : public MyBaseClass
{
public:
    DerivedClassOne(){};
    virtual ~DerivedClassOne(){};

    virtual void info() {
        std::cout << "C++ course" << std::endl; 
    }


    virtual void schedule() {
        std::cout << "C++ schedule" << std::endl; 
    }
};
#endif // CPPFACTORY_DERIVEDCLASSONE_H
