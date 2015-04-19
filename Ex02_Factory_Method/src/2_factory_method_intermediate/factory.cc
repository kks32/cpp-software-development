#include "factory.h"

//Factory method generates a product
std::shared_ptr<Course> MyCourseFactory::generatecourse(std::string& coursename) {

    Course* courseptr = NULL;
    
    if (coursename == "C++") {
        courseptr = new Cpp;
    }
    else if (coursename == "Java") {
        courseptr = new Java;
    }

    // Evaluating if the course exists
    if(courseptr != nullptr) {
        return std::shared_ptr<Course>(courseptr);
    }
    else {
        std::cerr << "Invalid course name. Program terminating" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}


