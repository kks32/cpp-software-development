#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <memory>
#include "course.h"

// Abstract Factory
class MyCourseFactory 
{
public:
    virtual ~MyCourseFactory(){}
    //Factory Method
    static std::shared_ptr<Course> generatecourse(std::string& coursename);
};

#endif
