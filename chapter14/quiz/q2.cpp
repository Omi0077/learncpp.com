#include <iostream>

class Fraction
{
  int m_num{0};
  int m_denum{1};

public:
  constexpr Fraction() {}
  // constexpr explicit Fraction(int x = 0, int y = 1)
  //     : m_num{x}, m_denum{y} {}
  // explicit to not implicitly convert single value to Fraction

  constexpr Fraction(int x, int y)
      : m_num{x}, m_denum{y} {}

  void read()
  {
    std::cout << "Enter numerator: ";
    std::cin >> m_num;
    std::cout << "Enter denominator: ";
    std::cin >> m_denum;
  }

  void print() const
  {
    std::cout << "(" << m_num << "/";
    std::cout << m_denum << ")\n";
  }

  constexpr Fraction multiply(const Fraction& other) const {
    return Fraction {m_num*other.m_num, m_denum*other.m_denum};
  }
};

int main()
{
  Fraction f1 {};
  f1.read();
  // f1 = f1.multiply({1,2});
  Fraction f2 {};
  f2.read();

  constexpr Fraction f3 {3,4};
  constexpr Fraction f4 {4,5};

  constexpr Fraction product {f3.multiply(f4)};
  product.print();
  return 0;
}