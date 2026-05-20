#include <iostream>

namespace Foo
{
  namespace Goo
  {
    void print()
    {
      std::cout << "hello world" << std::endl;
    }
  }
}

int main()
{
  Foo::Goo::print();
  return 0;
}