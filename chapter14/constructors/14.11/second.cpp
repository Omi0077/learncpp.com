#include <iostream>

class User{
  int m_x;
  int m_y{};

  public:
  User(){}
  int x() const { return m_x; }
  int y() const { return m_y; }
};

class Implicit{
  int m_x;
  int m_y{};

  public:
  int x() const { return m_x; }
  int y() const { return m_y; }
};

class Defaulted{
  int m_x;
  int m_y{};

  public:
  Defaulted() = default;
  int x() const { return m_x; }
  int y() const { return m_y; }
};

int main(){

  User u{};
  std::cout << u.x() << ' ' << u.y() << '\n'; // x here is not zero init 
  // more performant

  Implicit i{};
  std::cout << i.x() << ' ' << i.y() << '\n';

  Defaulted d{};
  std::cout << d.x() << ' ' << d.y() << '\n';

  // even more performant but less safe

  User u2;
  std::cout << u2.x() << ' ' << u2.y() << '\n'; // x here is not zero init 

  Implicit i2;
  std::cout << i2.x() << ' ' << i2.y() << '\n';

  Defaulted d2;
  std::cout << d2.x() << ' ' << d2.y() << '\n';

  return 0;
}