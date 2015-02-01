#include <iostream>

class Point {
  double Xcoord_, Ycoord_;

 public:
  Point();
  Point(double Xcoord, double Ycoord) : Xcoord_{Xcoord}, Ycoord_{Ycoord} {};
  double Xcoord() const { return Xcoord_; };
  void Xcoord(double newValue) { Xcoord_ = newValue; };
  double Ycoord() const { return Ycoord_; };
  void Ycoord(double newValue) { Ycoord_ = newValue; };
};

int main() {
  Point point{0., 0.};
  point.Xcoord(point.Xcoord() + 10.);
  std::cout << "The new xcoordinate is : " << point.Xcoord() << std::endl;
}
