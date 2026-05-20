#include <iostream>

template <typename T>
T max(T x, T y){
  return (x > y) ? x : y; 
}

// we can overload templates too
// always the stricter one will be choosed

// template <typename T, typename U>
// auto max(T x, U y){
//   return (x > y) ? x : y; 
// }
// so we put auto to let compiler decide return type, but it needs full definition


auto max(auto x, auto y){
  return (x > y) ? x : y;
}
// abbreviated function templates
// using auto as parameter type , lets compiler convert function to function template
// cpp 20

int main(){
  // std::cout << max(4,5.4) << "\n";
  // error cuz template type deduction doesnt use conversions

  std::cout << max<double>(4,5.4) << "\n"; 
  // this is valid cuz we didnt use type deduction so 4 is casted as 4.0

  std::cout << max(4,5.4) << "\n"; 
  // now this works too , but prints 5
  return 0;
}