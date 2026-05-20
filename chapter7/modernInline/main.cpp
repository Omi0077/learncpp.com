#include <iostream>

inline int add(int x, int y)
{
  // std::cout <<"this was called" << std::endl;
  return x+y;
}

int main(){
  std::cout<< add(4,5) << " " << std::endl;
}