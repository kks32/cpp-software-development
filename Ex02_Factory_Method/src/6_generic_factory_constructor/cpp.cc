#include "cpp.h"
#include "factory.h"

// Registering new course
//REGISTER_CLASS("C++", Cpp);
static Register<Course, Cpp> registry("C++");
