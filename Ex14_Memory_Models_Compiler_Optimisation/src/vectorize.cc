#include <iostream>

const int SIZE = 100000;
int main() {

  int a[SIZE], b[SIZE], c[SIZE];

  for (int i=0; i<SIZE; ++i){
    b[i] = 2*i;
    c[i] = 5*i;
  }

  for (int i=0; i<SIZE; ++i){
    a[i] = b[i] * c[i];
  }

}
