#ifndef _CPP_H_
#define _CPP_H_

#include "course.h"
#include <iostream>

class Cpp : public Course
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
