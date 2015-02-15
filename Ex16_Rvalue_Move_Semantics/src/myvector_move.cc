#include <iostream>
#include <cstdlib>

// Class MyVector
template <class T>
class Myvector {
 public:
  // Allocate i elements, initialised as 0, 1, ..., 1-1, n
  explicit Myvector<T>(int i) : size{i} {
    elems = new T[i]();
    for (int j = 0; j < i; ++j) {
      elems[j] = j;
    }
  }
  // Destructor
  ~Myvector<T>() { delete[] elems; }

  // Copy constructor
  Myvector<T>(const Myvector<T>& newvector) : size{newvector.size} {
    elems = new T[newvector.size];
    for (int i = 0; i < newvector.get_size(); ++i)
      elems[i] = newvector.elems[i];
  }

  // Assignment & move operator
  Myvector<T>& operator=(Myvector<T> newvector) {
    swap(newvector);
    return *this;
  }

  // Swap the vectors
  void swap(Myvector<T>& newvector) {
    std::swap(elems, newvector.elems);
    std::swap(size, newvector.size);
    // Inefficient way of doing this would be
    // Myvector<T> temp{newvector}; // unnecessary temp
    // newvector = *this;
    //*this = temp;
  }

  // Move construct
  Myvector<T>(Myvector<T>&& newvector) : size{0}, elems{nullptr} {
    swap(newvector);
  }

  // Alternative move construct
  // Myvector<T>(Myvector<T>&& newvector)
  //     : size{newvector.size}, elems{newvector.elems} {
  //   newvector.size = 0;
  //   newvector.elems = nullptr;  // no elements
  // }

  T& operator[](int index) const { return elems[index]; }
  int get_size() const { return size; }
  T* begin() { return elems; }       // begin iterator
  T* end() { return elems + size; }  // end iterator

 private:
  T* elems;
  int size;
};

int main() {
  Myvector<double> v{10};
  std::cout << "Elements in v" << std::endl;
  for (const auto& x : v) std::cout << x << std::endl;
  Myvector<double> v2 = std::move(v); // try just passing 'v' as well v2 = v;
  std::cout << "Elements in v2" << std::endl;
  for (const auto& x : v2) std::cout << x << std::endl;
  std::cout << "How about the size of v :" << v.get_size() << std::endl;
}
