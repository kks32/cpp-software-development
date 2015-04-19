#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// Store account name, account no, balance
using accounts = std::tuple<std::string, unsigned, double>;

void print_account_info(const accounts& account) {
  std::cout << "( " << std::get<0>(account) << ", " << std::get<1>(account)
            << ", " << std::get<2>(account) << " )" << std::endl;
}

int main() {
  // Using the constructor to declare and initialize a tuple
  accounts alice{"Alice", 42, 748.90};

  // Compare using the helper function to declare and initialize a tuple
  // aka Packing values in a tuple
  auto bob = std::make_tuple("Bob", 10, -15.12);

  // Making a copy of a tuple
  accounts alice2(alice);

  // Size of a tuple
  std::cout << "The size of tuple alice is: "
            << std::tuple_size<decltype(alice)>::value << std::endl;

  // Accessing element type
  std::tuple_element<0, decltype(bob)>::type first = std::get<0>(bob);
  std::cout << "The first element in tuple bob is: " << first << std::endl;

  // Unpacking a tuple
  int accountno;
  double balance;
  std::tie(std::ignore, accountno, balance) = alice2;
  std::cout << "Account no of alice2 is: " << accountno
            << " and her balance is: " << balance << std::endl;

  std::vector<accounts> vaccounts;
  std::string str = "Eve";

  vaccounts.push_back(alice);
  vaccounts.push_back(bob);
  vaccounts.push_back(std::forward_as_tuple(str + " Smith", 23, 344.12));

  std::cout << "The tuples in the vector are" << std::endl;
  for (auto account : vaccounts) print_account_info(account);
}
