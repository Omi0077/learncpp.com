#include <iostream>

template <typename T, typename U, typename V>
struct Triad{
  T first{};
  U second{};
  V third{};
};

// deduction guide for c++17
template<typename X, typename Y, typename Z> // so template def. can have different name
Triad(X, Y, Z) -> Triad<X, Y, Z>;            // cuz at end its template

template <typename T, typename U, typename V>
void print(Triad<T, U, V> t){
  std::cout << "[";
  std::cout << t.first << ", ";
  std::cout << t.second << ", ";
  std::cout << t.third << "]";
}

int main(){

  Triad t1{1,2,3};
  print(t1);

  Triad t2{1.5,2.5,3.5};
  print(t2);

  return 0;
}