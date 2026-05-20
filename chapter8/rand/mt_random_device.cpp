#include <iostream>
#include <random>

int main(void)
{
  std::mt19937 mt {std::random_device{}()};

  // setting range
  std::uniform_int_distribution die6 {1,6};

  for(auto i=0;i<10; i++)
    std::cout << die6(mt) << " ";

  return 0;
}