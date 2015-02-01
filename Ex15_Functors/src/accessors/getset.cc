#include <iostream>

class Point {
  double Xcoord_, Ycoord_;

 public:
  Point();
  Point(double Xcoord, double Ycoord) : Xcoord_{Xcoord}, Ycoord_{Ycoord} {};
  double getXcoord() const { return Xcoord_; };
  void setXcoord(double newValue) { Xcoord_ = newValue; };
  double getYcoord() const { return Ycoord_; };
  void setYcoord(double newValue) { Ycoord_ = newValue; };
};

int main() {
  Point point{0., 0.};
  point.setXcoord(point.getXcoord() + 10.);
  std::cout << "The new xcoordinate is : " << point.getXcoord() << std::endl;
}
