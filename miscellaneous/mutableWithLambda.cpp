#include <iostream>

int main()
{
  int x = 50;
  auto f = [x]() mutable
  {
    x++;
    ++++++x;
    std::cout<<x<<std::endl;
  };

  f();
  std::cout<< x <<std::endl;

}