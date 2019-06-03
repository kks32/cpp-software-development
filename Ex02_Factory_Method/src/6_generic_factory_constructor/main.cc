#include <cstdlib>
#include <iostream>

#include "course.h"
#include "factory.h"

// Client-side implementation
int main(int argc, char **argv) {

  // User input
  if (argc != 2) {
    std::cerr << "Incorrect number of arguments" << std::endl;
    std::cerr << "Usage: ./factory course  (C++/Java)" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  std::string coursename = argv[1];

  auto mycourse = Factory<Course>::instance()->create(coursename);

  mycourse->info();
  mycourse->schedule();
}
