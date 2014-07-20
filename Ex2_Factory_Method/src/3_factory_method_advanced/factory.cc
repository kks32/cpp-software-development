#include "factory.h"




Registrar::Registrar(std::string name, std::function<Course*(void)> classFactoryFunction)
{
    // register the class factory function
    MyCourseFactory::Instance()->RegisterFactoryFunction(name, classFactoryFunction);
}


MyCourseFactory * MyCourseFactory::Instance()
{
    static MyCourseFactory factory;
    return &factory;
}


void MyCourseFactory::RegisterFactoryFunction(std::string name, std::function<Course*(void)> classFactoryFunction)
{
    // register the class factory function 
    factoryFunctionRegistry[name] = classFactoryFunction;
}


std::shared_ptr<Course> MyCourseFactory::Create(std::string name)
{
    Course * instance = nullptr;

    // find name in the registry and call factory method.
    auto it = factoryFunctionRegistry.find(name);
    if(it != factoryFunctionRegistry.end())
        instance = it->second();
    
    // wrap instance in a shared ptr and return
    if(instance != nullptr)
        return std::shared_ptr<Course>(instance);
    else
        return nullptr;
}
