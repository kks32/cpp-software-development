#ifndef _NET_H_
#define  _NET_H_

#include "course.h"
#include <iostream>

class Net : public Course
{
public:
    Net(){};
    virtual ~Net(){};

    virtual void info() {
        std::cout << "Net course" << std::endl;
    }

    virtual void schedule() {
        std::cout << "Net schedule" << std::endl;
    }
};
#endif //  _Net_H_
