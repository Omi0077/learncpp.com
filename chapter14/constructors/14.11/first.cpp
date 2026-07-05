#include <iostream>

class Foo
{
  int m_x;
  int m_y{};

public:
  // Foo() = default;
  Foo(int x = 0, int y = 0) // cant have 2 default constructor
      : m_x{x}, m_y{y}
  {
  }

  void print() const
  {
    std::cout << "[" << m_x << ", " << m_y << "]\n";
  }
};

int main()
{
  Foo f{};
  f.print();
  return 0;
}