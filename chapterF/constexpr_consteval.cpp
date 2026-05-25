#include <iostream>
#include <type_traits>

constexpr int getInt(int a){
  if consteval{
    return a*50;
  }
  if(std::__is_constant_evaluated()){
    return a;
  }
  else{
    return a*a;
  }
}

// compiler may evaluate a constexpr func in context where constant expression isnt
// required then __is_constant_evaluated() will be false
//  So std::is_constant_evaluated() really means “the compiler is being forced to evaluate
//  this at compile-time”, not “this is evaluating at compile-time”.

/*
A pure function is a function that meets the following criteria:

-The function always returns the same return result when given the same arguments
-The function has no side effects (e.g. it doesn’t change the value of static local or global variables, doesn’t do input or output, etc…).

Pure functions should generally be made constexpr.
*/

int main(){
  constexpr int a {getInt(100)};
  int b {getInt(100)};

  std::cout<< a << " " << b << "\n";
  return 0;
}