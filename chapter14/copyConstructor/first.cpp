#include <iostream>

class Fraction
{
  int m_numerator{};
  int m_denominator{};

public:
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {}

  Fraction(const Fraction &other)
      : m_numerator{other.m_numerator}, m_denominator{other.m_denominator}
  {
    std::cout << "object copied\n";
  }

  // Fraction(const Fraction& other) = delete;

  void print() const
  {
    std::cout << "Fraction(" << m_numerator << "/" << m_denominator << ")\n";
  }
};

// pass by value
void print(const Fraction f)
{
  f.print();
}

// return by value
Fraction createFraction(int n, int d)
{
  Fraction f{n, d};
  return f;
}

int main()
{

  // Fraction f1 {5, 2};
  // Fraction f2 {f1};

  Fraction f{createFraction(5, 3)}; // copies are getting optimized out
  print(f);

  return 0;
}