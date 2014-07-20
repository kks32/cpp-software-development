#include "MyFactorySimple.h"

int main(int argc, char** argv)
{
    auto instanceOne = MyFactory::CreateInstance("one");
    auto instanceTwo = MyFactory::CreateInstance("two");
    
    instanceOne->doSomething();
    instanceTwo->doSomething();
    
    return 0;
}