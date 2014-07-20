#include <cstdlib>
#include <iostream>
#include <memory>

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


// Abstract Factory
class MyCourseFactory 
{
public:
    virtual ~MyCourseFactory(){}
    //Factory Method
    static std::shared_ptr<Course> generatecourse(std::string& coursename);
};

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

// Client side implementation 
int main(int argc, char* argv[]) {

    // User input
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        std::cerr << "Usage: ./factory course  (C++/Java)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string coursename = argv[1];

    auto mycourse = MyCourseFactory::generatecourse(coursename);
    mycourse->info();
    mycourse->schedule();

    return 0;
}
