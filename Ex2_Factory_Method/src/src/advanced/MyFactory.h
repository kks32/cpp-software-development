#ifndef CPPFACTORY_MYFACTORY_H
#define CPPFACTORY_MYFACTORY_H

#include "MyBaseClass.h"

#include <memory>
#include <string>
#include <map>
#include <functional>

using namespace std;

// A helper class to register a factory function
class Registrar {
public:
    Registrar(string className, function<MyBaseClass*(void)> classFactoryFunction);
};

// A preprocessor define used by derived classes
#define REGISTER_CLASS(NAME, TYPE) static Registrar registrar(NAME, [](void) -> MyBaseClass * { return new TYPE();});

// The factory - implements singleton pattern!
class MyFactory
{
public:
    // Get the single instance of the factory
    static MyFactory * Instance();

    // register a factory function to create an instance of className
    void RegisterFactoryFunction(string name, function<MyBaseClass*(void)> classFactoryFunction);

    // create an instance of a registered class
    shared_ptr<MyBaseClass> Create(string name);

private:
    // a private ctor
    MyFactory(){}

    // the registry of factory functions
    map<string, function<MyBaseClass*(void)>> factoryFunctionRegistry;

};

#endif // CPPFACTORY_MYFACTORY_H