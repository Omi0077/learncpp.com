#include <iostream>

int main()
{
  goto here;
  // int x = 5; // this jumps thus causes error
  std::cout<<"hellow";

here:
  ;
  return 0;
}