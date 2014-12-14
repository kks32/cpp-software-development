#include <thread>
#include <mutex>
#include <iostream>


class Account {
  std::mutex mutex;
  double i;
public:
  Account() : i(0) {}
  void credit(double x){
    std::lock_guard<std::mutex> lock(mutex);
    i += x;
  }
  void debit(double x){
    std::lock_guard<std::mutex> lock(mutex);
    i -= x;
  }
  void both(double x, double y){
    std::lock_guard<std::mutex> lock(mutex);
    credit(x);
    debit(y);
  }

  double print() { return i;}
};
int main(){
  Account savings;
  savings.both(32, 23);
  std::cout << "Balance is : " <<  savings.print() << std::endl;
}
