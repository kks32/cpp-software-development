#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
 public:
  Complex(double real, double imaginary = 0)
      : _real(real), _imaginary(imaginary) {}
  void operator+(Complex other) {
    _real = _real + other._real;
    _imaginary = _imaginary + other._imaginary;
  }
  void operator<<(ostream os) {
    os << "(" << _real << "," << _imaginary << ")";
  }
  Complex operator++() {
    ++_real;
    return *this;
  }
  Complex operator++(int) {
    Complex temp = *this;
    ++_real;
    return temp;
  }

 private:
  double _real, _imaginary;
};

#endif  // _COMPLEX_H_
