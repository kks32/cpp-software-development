#include <iostream>
using namespace std;

double division(double a, double b)
{
   if( b == 0. )
   {
      throw "\nDivision by zero condition!";
   }
   return (a/b);
}

int main ()
{
   double x, y;
   double z = 0.;
   std::cout << "\nEnter the value of the numerator: ";
   std::cin >> x;
   std::cout << "\nEnter the value of the denominator: ";
   std::cin >> y;

   try {
     z = division(x, y);
     cout << "The result is: " << z << endl;
  }catch (const char* msg) {
     cerr << msg << endl;
  }

  std::cout << "\nThe code continues after excpetion" << std::endl;
  return 0;
}
