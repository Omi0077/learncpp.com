#include <iostream>
#include <array>

int main()
{
  // int array[100000000] {};

  std::array<int, 1000000> *p{};
  while (true)
  {
    p = new (std::nothrow) std::array<int, 1000000>;
    // delete p;

    if (!p)
    {
      std::cout << "no memory left lol\n";
      break;
    }
  }

  return 0;
}