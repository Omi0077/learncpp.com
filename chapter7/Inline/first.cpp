#include <iostream>

inline int min(int x, int y)
{
  return (x>y) ? x : y ;
}

int main()
{
  std::cout << min(4,5) << std::endl;
  std::cout << min(10,5) << std::endl;
  return 0;
}