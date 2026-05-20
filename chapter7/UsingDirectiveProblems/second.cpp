#include <iostream>

namespace A
{
  int x{10};
}


int main()
{
  std::cout << A::x << std::endl;
  return 0;
}