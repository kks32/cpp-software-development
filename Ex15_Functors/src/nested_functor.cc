#include <iostream>

int f ( int i ) {
  int j = i*2;
  class g_ {
  public:
    g_( int& j ) : j_( j ) { }
    // access j via a reference
    int operator()( int k ) { return j_+k; }
  private:
    int& j_;
  } g( j );
  j += 4;
  return g( 3 );
}

int main() {
  std::cout << "Value of f(5) is : " << f(5) << std::endl;
}
