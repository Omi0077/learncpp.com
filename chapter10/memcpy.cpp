#include <iostream>
#include <cstring>

int main(void)
{
  int i {3};
  float f {};
  std::memcpy(&f, &i, sizeof(float));
  std::cout << "the value of f is : " << f << "\n";
  return 0;
}