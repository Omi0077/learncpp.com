#include <iostream>

namespace
{
  void thisDoesSomething() // this function isnt visible outside this file
  {
    std::cout << "GG" << std::endl;
  }
}

int main()
{
  thisDoesSomething();
  return 0;
}