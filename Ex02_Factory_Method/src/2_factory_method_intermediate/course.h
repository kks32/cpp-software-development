#ifndef _COURSE_H_
#define _COURSE_H_

#include <cstdlib>
#include <memory>
#include <iostream>

// Abstract Product: Course
class Course
{
public:
    virtual ~Course(){}

    virtual void info() = 0;
    virtual void schedule() = 0;
};
 
// Concrete Product: C++
class Cpp : public Course
{
public:
    virtual ~Cpp(){}
    void info(){
        std::cout << "This is a C++ Course" << std::endl;
    }

    void schedule(){
        std::cout << "This is the C++ course schedule" << std::endl;
    }
};

// Concrete Product: Java
class Java : public Course
{
public:
    virtual ~Java(){}
    void info(){
        std::cout << "This is a Java Course" << std::endl;
    }
    void schedule(){
        std::cout << "This is the Java course schedule" << std::endl;
    }

};

#endif
