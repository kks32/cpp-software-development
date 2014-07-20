#ifndef CPPFACTORY_MYFACTORY_H
#define CPPFACTORY_MYFACTORY_H

#include "MyBaseClass.h"
#include <memory>
#include <string>

using namespace std;

class MyFactory
{
public:
    static shared_ptr<MyBaseClass> CreateInstance(string name);
};

#endif // CPPFACTORY_MYFACTORY_H