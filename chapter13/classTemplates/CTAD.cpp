#include <iostream>

// default value only used when template parameters isnt explicitly specified and cant be deduced
template <typename T=int, typename U=int>
struct Pair{
  T first{};
  U second{};
};

// deduction guide
template <typename T, typename U>
Pair(T, U) -> Pair<T,U>;

// struct Something{
//   int x{5};
//   Pair p{5,6}; // CTAD isnt used for non-static member initialization
// };

// void print(Pair p){
//   // error CTAD isnt used for Template parameters of functions
// }

int main(){
  Pair<int, double> p1{1,1.5};
  Pair p2{1,2};

  Pair p3; // default template parameters used
  return 0;
}