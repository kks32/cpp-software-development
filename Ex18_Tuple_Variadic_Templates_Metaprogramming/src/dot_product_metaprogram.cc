#include <iostream>

// primary template
template <int DIM, typename T>
class DotProduct {
 public:
  static T result(T* a, T* b) {
    return *a * *b + DotProduct<DIM - 1, T>::result(a + 1, b + 1);
  }
};

// partial specialization as end criteria
template <typename T>
class DotProduct<1, T> {
 public:
  static T result(T* a, T* b) { return *a * *b; }
};

// convenience function
template <int DIM, typename T>
inline T dot_product(T* a, T* b) {
  return DotProduct<DIM, T>::result(a, b);
}

int main() {
  int a[3] = {1, 2, 3};
  int b[3] = {5, 6, 7};

  std::cout << "dot_product<3>(a,b) = " << dot_product<3>(a, b) << std::endl;
  std::cout << "dot_product<3>(a,a) = " << dot_product<3>(a, a) << std::endl;
}
