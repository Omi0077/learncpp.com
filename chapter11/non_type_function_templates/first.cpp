#include <iostream>

// templates can have non-type template parameters
// for valid non-types : https://www.learncpp.com

// one usecase of non-type parameters are to send constexpr values to function

// void printPositive(constexpr int a){
//   static_assert(a >= 0, "negative value not accepted\n");

//   std::cout << a << "\n";
// }
// this results in error as parameters cant be constexpr

template <int N>
void printPositive(){
  static_assert(N >= 0, "negative value not accepted\n");

  std::cout << N << "\n";
}

int main(){
  printPositive<5>();
  // call to this instantiates following function
  // template <>
  // void printPositive<5>(){
  //   static_assert(5 >= 0, "negative value not accepted\n");

  //   std::cout << 5 << "\n";
  // }
  
  // giving it a constant expression
  return 0;
}

/*

*/