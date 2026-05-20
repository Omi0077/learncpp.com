#include <iostream>

namespace Foo::Goo // this was allowed from cpp 17
{
  void print()
  {
    std::cout << "this is inside Foo::Goo" << std::endl;
  }
}

namespace Foo
{
  void print()
  {
    std::cout << "this is only in Foo" << std::endl;
  }
}

int main()
{
  Foo::Goo::print();
  Foo::print();

  // to avoid these long sequences fo namespaces we can create aliases of namespaces
  namespace Yo = Foo::Goo;

  // we can also change where the alias refers
  // namespace Yo = Foo;

  Yo::print();

  return 0;
}