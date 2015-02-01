#include <iostream>

template<class Tcoord>
class Coordinate {
  Tcoord coord_;

 public:
  Coordinate();
  explicit Coordinate(Tcoord coord) : coord_{coord} {};
  Tcoord operator()() const { return coord_; }
  void operator()(Tcoord coord) { coord_ = coord; }
};

class Point {
 public:
  Coordinate<double> Xcoord, Ycoord;
  Point();
  Point(double X, double Y) : Xcoord{X}, Ycoord{Y} {};

};

int main() {
  Point point{0., 0.};
  point.Xcoord(point.Xcoord() + 10.);
  std::cout << "The new xcoordinate is : " << point.Xcoord() << std::endl;
}


