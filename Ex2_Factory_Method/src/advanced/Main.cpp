#include "MyFactory.h"

#include <cstdlib>
#include <iostream>


int main(int argc, char** argv)
{

    // User input
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments" << std::endl;
        std::cerr << "Usage: ./factory course  (C++/Java)" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::string coursename = argv[1];

    auto mycourse = MyFactory::Instance()->Create(coursename);
    
    mycourse->info();

    return 0;
}
