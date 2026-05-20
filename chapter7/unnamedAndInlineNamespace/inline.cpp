#include <iostream>

inline namespace v1
{
  void doSomething()
  {
    std::cout << "v1" << std::endl;
  }
}

namespace v2
{
  void doSomething()
  {
    std::cout << "v2" << std::endl;
  }
}
