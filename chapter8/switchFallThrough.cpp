#include <iostream>

int main(void)
{
  int a = 5;

  switch(a)
  {
  case 1:
    std::cout << " its 1\n";
    break;
  case 5:
    std::cout << " its 5\n";
    [[fallthrough]];
  case 3:
    std::cout << " its 3\n";
  case 4:
    std::cout << " its 4\n";
  }
  return 0;
}