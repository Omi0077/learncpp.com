#include <iostream>
#include "myLib.h"

int get(long){return 5;} // needs type conversion

int main()
{
  using namespace yo;
  std::cout << get(20) << std::endl;
  return 0;
}