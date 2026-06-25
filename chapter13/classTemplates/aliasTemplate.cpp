#include <iostream>

template <typename T>
struct Pair{
  T first{};
  T second{};
};

template <typename T>
Pair(T, T) -> Pair<T>;

// but if we dont wanna specify all args
// we can use alias template which instantiates type aliases
template <typename T>
using Coord = Pair<T>;

// void print(Coord<int> &c){ // CTAD doesnt work here, so add template args explicitly, only int
//   std::cout << "[" << c.first << " " << c.second << "]" << "\n";
// }

template <typename T>
void print(Coord<T> &c){ // CTAD doesnt work here, so add template args explicitly, only int
  std::cout << "[" << c.first << " " << c.second << "]" << "\n";
}

int main(){

  // we can define alias to class template where all args are specified
  // just like normal alias
  using Point = Pair<int>;
  Point p1{1,2};

  Coord<int> c1 {1,2};
  Coord c2{2,3}; // alias template deduction via CTAD wont work prior to c++20
  Coord c3{2.5,3.5}; // alias template deduction via CTAD wont work prior to c++20

  print(c2);
  print(c3);

  return 0;
}