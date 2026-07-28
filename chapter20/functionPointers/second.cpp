#include <iostream>

void print(int a){
  std::cout << a << '\n';
}

void print(int a, int b = 30){
  std::cout << a << ' ' << b << '\n';
}

int main(){
  // print(10); error

  using vptr = void(*)(int); // doesnt work with default args , u either specify the args or not
  vptr p {print};
  p(10); // no ambiguous call
  return 0;
}