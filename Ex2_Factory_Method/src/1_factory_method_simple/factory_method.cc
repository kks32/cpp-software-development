#include <cstdlib>
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


// Abstract Factory
class CourseFactory 
{
public:
    virtual ~CourseFactory(){}
    virtual Course* generatecourse() = 0;
    //Factory Method
    static CourseFactory* create_course(std::string& coursename);
};


// Concrete factory: C++
class CppFactory : public CourseFactory 
{
public:
    virtual ~CppFactory(){}
    Course* generatecourse(){
        return new Cpp;
    }
};

// Concrete factory: Java
class JavaFactory : public CourseFactory 
{
public:
    virtual ~JavaFactory(){}
    Course* generatecourse(){
        return new Java;
    }
};

//Factory method generates a product
CourseFactory* CourseFactory::create_course(std::string& coursename) {

    CourseFactory* course = NULL;
    
    if (coursename == "C++") {
        course = new CppFactory;
    }
    else if (coursename == "Java") {
        course = new JavaFactory;
    }
    else {
        std::cerr << "Invalid course name. Program terminating" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return course;
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

    CourseFactory* newcourse = CourseFactory::create_course(coursename);
    Course* course = newcourse->generatecourse();
    course->info();
    course->schedule();

    delete course;
    delete newcourse;

    return 0;
}
