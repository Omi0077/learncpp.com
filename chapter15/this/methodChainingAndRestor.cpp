#include <iostream>

class Calc
{
  int m_val{};

public:
  Calc(int val) : m_val{val} {}
  Calc() {}
  Calc &add(int val)
  {
    m_val += val;
    return *this;
  }
  Calc &sub(int val)
  {
    m_val -= val;
    return *this;
  }
  Calc &mult(int val)
  {
    m_val *= val;
    return *this;
  }
  Calc &div(int val)
  {
    m_val /= val;
    return *this;
  }

  void restore()
  {
    *this = {};
  }

  void print() const
  {
    std::cout << "val: " << m_val << '\n';
  }
};

int main()
{
  Calc c{5};

  c.add(5).sub(2).mult(4).div(3).print();
  c.restore();
  c.print();
  return 0;
}