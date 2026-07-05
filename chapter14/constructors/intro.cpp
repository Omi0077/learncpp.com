#include <iostream>

int main()
{
  class Something
  {
    int m_lol{};

  public:
    Something()
    {
      m_lol = 69;
    }

    int get() const
    {
      return m_lol;
    }
  };

  Something s{};
  std::cout << s.get() << "\n";

  const Something s2{};          // const object but implicitly invokes (non-const) constructor
  std::cout << s2.get() << "\n"; // error if get isnt const

  return 0;
}