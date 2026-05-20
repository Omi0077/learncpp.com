#include <iostream>

int main(void)
{
  int a = 5;

  switch(a)
  {
  case 1:
    std::cout << " its 1\n";
    int a;
    a = 5;
    break;
  case 5:
    std::cout << " its 5\n" << a; // a has garbage value as previous case isnt executed
    break;
  case 3:
    std::cout << " its 3\n";
    {
      int x = 16; // this works as x exists only inisde these braces, so even if its jumped no problem
    }
    break;
  case 4:
    std::cout << " its 4\n";
    int b = 7;  // this works cuz its last and cannot be jumped over
    break;
  }
  return 0;
}