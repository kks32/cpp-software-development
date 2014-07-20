#include "MyFactorySimple.h"

#include "DerivedClassOne.h"
#include "DerivedClassTwo.h"

shared_ptr<MyBaseClass> MyFactory::CreateInstance(string name)
{
    MyBaseClass * instance = nullptr;

    if(name == "one")
        instance = new DerivedClassOne();
    
    if(name == "two")
        instance = new DerivedClassTwo();
    
    if(instance != nullptr)
        return std::shared_ptr<MyBaseClass>(instance);
    else
        return nullptr;
}