#include <iostream>

int main(){
  short x{5};

  // int& ref {x}; // error

  const int& ref2{x}; // ok , bound to temporary object
  std::cout << x << ref2 <<"\n";
  x = 7;
  std::cout << x << ref2 <<"\n";
  return 0;
}