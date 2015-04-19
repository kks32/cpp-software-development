#include <iostream>

template <typename T>
inline T dot_product(int dim, T* a, T* b) {
  T result = 0;
  for (int i = 0; i < dim; ++i) {
    result += a[i] * b[i];
  }
  return result;
}

int main() {
  int a[3] = {1, 2, 3};
  int b[3] = {5, 6, 7};

  std::cout << "dot_product(3,a,b) = " << dot_product(3, a, b) << std::endl;
  std::cout << "dot_product(3,a,a) = " << dot_product(3, a, a) << std::endl;
}
