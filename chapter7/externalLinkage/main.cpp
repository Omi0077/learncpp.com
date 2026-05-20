#include <iostream>

extern int a;
extern const int b;
extern const int c;

int main()
{
  // c = 60;
  std::cout << a << " " << b << " " << c << std::endl;
  return 0;
}