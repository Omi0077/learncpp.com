#include <iostream>

template <typename T>
T max(T x, T y){
  return (x > y) ? x : y;
}

int main(){
  std::cout << max<float>(5,4) << "\n";
  std::cout << max<int>(5.5,5.4) << "\n";
  /*
  When the compiler encounters the function call max<int>(1, 2), it will determine that a function definition for max<int>(int, int) does not already exist. Consequently, the compiler will implicitly use our max<T> function template to create one.
  */

  /*
  When a function is instantiated due to a function call, it’s called implicit instantiation. A function that is instantiated from a template is technically called a specialization, but in common language is often called a function instance. 
  */
  return 0;
}