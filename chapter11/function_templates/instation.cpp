#include <iostream>

template <typename T>
T max(T x, T y){
  return (x > y) ? x : y; 
}

int main(){
  std::cout << max<int>(4,5) << "\n"; // instantiates and calls max<int>(int,int)
  std::cout << max<int>(9,23) << "\n"; // calls already instantiaded max<int>(int,int)
  std::cout << max<double>(4,5) << "\n"; // instantiates and calls max<double>(double,double)

  /*A function template is only instantiated the first time a function call is made in each translation unit.*/

  // type can be deduced from arguments if not provided;

  max<>(10,30); // deduces type int
  max(10,30); // deduces type int

  // in first case non-template function overloads arent considered
  // in second case both template and non-template overloads are considered
  // infact in second case non-template int max(int,int) will be prioritized over
  // a template instantiated max<int>(int,int)
}