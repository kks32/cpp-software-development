#ifndef _COURSE_H_
#define _COURSE_H_

//Abstract Base Class
class Course
{
public:
    virtual void info() = 0;
    virtual void schedule() = 0;
};

#endif //  _COURSE_H_
