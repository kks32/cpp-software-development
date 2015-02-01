#include <iostream>

class Coordinate {
  double coord_;

 public:
  Coordinate();
  Coordinate(double coord) : coord_{coord} {};
  double operator()() const { return coord_; }
  void operator()(double coord) { coord_ = coord; }
};

class Point {
 public:
  Coordinate Xcoord, Ycoord;
  Point();
  Point(double X, double Y) : Xcoord{X}, Ycoord{Y} {};

};

int main() {
  Point point{0., 0.};
  point.Xcoord(point.Xcoord() + 10.);
  std::cout << "The new xcoordinate is : " << point.Xcoord() << std::endl;
}


