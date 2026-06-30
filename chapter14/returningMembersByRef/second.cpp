#include <iostream>

class Foo
{
  int m_value{};

public:
  void setValue(int value) { m_value = value; }
  // int &getValue() const { return m_value; } // error const member can return non-cosnt ref to members
  const int &getValue() const { return m_value; } 

  int &modifyValue() { return m_value; } // bad practice fucks private concept
};

int main()
{

  Foo f;
  f.setValue(10);

  f.modifyValue() = 50; // changes private member
  // f.getValue() = 50; // cant change via const lvalue ref
  std::cout << f.getValue() << "\n";

  return 0;
}