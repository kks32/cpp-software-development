#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "course.h"

#include <memory>
#include <string>
#include <map>
#include <functional>

//using namespace std;

// A helper class to register a factory function
class Registrar {
public:
    Registrar(std::string className, std::function<MyBaseClass*(void)> classFactoryFunction);
};

// A preprocessor define used by derived classes
#define REGISTER_CLASS(NAME, TYPE) static Registrar registrar(NAME, [](void) -> MyBaseClass * { return new TYPE();});

// The factory - implements singleton pattern!
class MyCourseFactory
{
public:
    // Get the single instance of the factory
    static MyCourseFactory * Instance();

    // register a factory function to create an instance of className
    void RegisterFactoryFunction(std::string name, std::function<MyBaseClass*(void)> classFactoryFunction);

    // create an instance of a registered class
    std::shared_ptr<MyBaseClass> Create(std::string name);

private:
    // a private ctor
    MyCourseFactory(){}

    // the registry of factory functions
    std::map<std::string, std::function<MyBaseClass*(void)>> factoryFunctionRegistry;

};

#endif // _FACTORY_H_
