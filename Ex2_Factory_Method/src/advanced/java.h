#ifndef _JAVA_H_
#define _JAVA_H_

#include "MyBaseClass.h"
#include <iostream>

class Java : public MyBaseClass
{
public:    
    Java(){};
    virtual ~Java(){};

    virtual void info() {
        std::cout << "Java course" << std::endl; 
    }

    virtual void schedule() {
        std::cout << "Java schedule" << std::endl; 
    }
};
#endif //  _JAVA_H_
