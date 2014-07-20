#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "course.h"

#include <memory>
#include <string>
#include <map>
#include <functional>

//using namespace std;

// The factory - implements singleton pattern!
class MyCourseFactory
{
public:
    // Get the single instance of the factory
    static MyCourseFactory* Instance();

    // register a factory function to create an instance of className
    void RegisterFactoryFunction(std::string name, std::function<Course*(void)> classFactoryFunction);

    // create an instance of a registered class
    std::shared_ptr<Course> Create(std::string name);

private:
    // a private ctor
    MyCourseFactory(){}

    // the registry of factory functions
    std::map<std::string, std::function<Course*(void)>> factoryFunctionRegistry;

};


// A helper class to register a factory function
template<class T>
class Registrar {
public:
    Registrar(std::string className)
    {
        // register the class factory function
        MyCourseFactory::Instance()->RegisterFactoryFunction(className,
                [](void) -> Course* { return new T();});
    }
};



#endif // _FACTORY_H_
