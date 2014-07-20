#ifndef _CPP_H_
#define _CPP_H_

#include "MyBaseClass.h"
#include <iostream>

class Cpp : public MyBaseClass
{
public:
    Cpp(){};
    virtual ~Cpp(){};

    virtual void info() {
        std::cout << "C++ course" << std::endl; 
    }


    virtual void schedule() {
        std::cout << "C++ schedule" << std::endl; 
    }
};
#endif //  _CPP_H_
