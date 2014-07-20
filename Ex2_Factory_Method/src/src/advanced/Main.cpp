#include "MyFactory.h"

int main(int argc, char** argv)
{
    auto instanceOne = MyFactory::Instance()->Create("one");
    auto instanceTwo = MyFactory::Instance()->Create("two");
    
    instanceOne->doSomething();
    instanceTwo->doSomething();
    
    return 0;
}