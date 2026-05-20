#include <iostream>

int main()
{
  // constexpr int a = 5;
  // short s1 {a};
  // std::cout << s1 << "\n";

  // constexpr int b = -5;
  // unsigned int u2 = b;
  // std::cout << u2 << "\n";

  // int x = 5;
  // short s = x;

  constexpr double d = 5.0;
  int i {d};  

  constexpr double d2 = 1.987654321;
  float f {d2};
  return 0;
}