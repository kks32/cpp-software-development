#include <iostream>
#include <string>

template <typename T>
T summation(T v) {
  return v;
}

template <typename T, typename... Args>
T summation(T first, Args... args) {
  return first + summation(args...);
}

int main() {
  std::cout << "Sum of integers: " << summation(1, 2, 3, 4, 5) << std::endl;
  std::string str1 = "C++", str2 = " is ", str3 = "great!";
  std::cout << "Concatenate strings: " << summation(str1, str2, str3)
            << std::endl;
}
