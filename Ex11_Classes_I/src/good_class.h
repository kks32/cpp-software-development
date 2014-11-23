// Example from Herb Sutter's Exception C++
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
 public:
  // Constructor
  explicit Complex(double real, double imaginary = 0)
      : real_(real), imaginary_(imaginary) {}

  // Assignment operator
  Complex& operator+=(const Complex& other) {
    real_ += other.real_;
    imaginary_ += other.imaginary_;
    return *this;
  }

  // Preincreament operator
  Complex& operator++() {
    ++real_;
    return *this;
  }

  // Post-increament operator
  const Complex operator++(int) {
    Complex temp(*this);
    ++*this;
    return temp;
  }

  // Print function
  ostream& Print(ostream& os) const {
    return os << "(" << real_ << "," << imaginary_ << ")";
  }

 private:
  double real_, imaginary_;
};

// Addition operator
const Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex ret(lhs);
  ret += rhs;
  return ret;
}

// Output stream
ostream& operator<<(ostream& os, const Complex& c) { return c.Print(os); }

#endif  // _COMPLEX_H_
