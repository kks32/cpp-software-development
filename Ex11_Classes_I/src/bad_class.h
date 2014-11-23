// Example from Herb Sutter's Exception C++

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
 public:
  // Constructor
  Complex(double real, double imaginary = 0)
      : _real(real), _imaginary(imaginary) {}

  // Addition operator
  void operator+(Complex other) {
    _real = _real + other._real;
    _imaginary = _imaginary + other._imaginary;
  }

  // << operator
  void operator<<(ostream os) {
    os << "(" << _real << "," << _imaginary << ")";
  }

  // Pre-Increament Operator
  Complex operator++() {
    ++_real;
    return *this;
  }

  // Post-increament operator
  Complex operator++(int) {
    Complex temp = *this;
    ++_real;
    return temp;
  }

 private:
  double _real, _imaginary;
};

#endif  // _COMPLEX_H_
