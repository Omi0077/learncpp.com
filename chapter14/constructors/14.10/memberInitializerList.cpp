#include <iostream>

class Foo
{
  int m_x{};
  int m_y{};

public:
  Foo(int x, int y)
      : m_y{y}, m_x{x}
  {
    // m_x will we be initialized first as member init list does memberwise init

    // constructor body executes after each data member is initialized via -:
    // member init list > default member initializer > default initialized
  }

  void print()
  {
    std::cout << "(" << m_x << ", " << m_y << ")\n";
  }
};

int main()
{
  Foo f1{5, 6};
  f1.print();
  return 0;
}