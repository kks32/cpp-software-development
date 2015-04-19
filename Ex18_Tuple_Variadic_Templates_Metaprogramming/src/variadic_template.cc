#include <iostream>
#include <vector>

// Calculate the number of items in the container

template <typename... Args>
struct count;

// Basis case with zero arguments
template <>
struct count<> {
  static const int value = 0;
};

// Recursive unpacking
template <typename T, typename... Args>
struct count<T, Args...> {
  static const int value = 1 + count<Args...>::value;
};

int main() {
  std::cout << "Size of the variadic Templates : "
            << count<int, char, short, std::vector<double>>::value << std::endl;
}
