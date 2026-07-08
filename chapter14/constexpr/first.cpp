#include <iostream>

class Pair{
  int m_x{};
  int m_y{};

  public:
  explicit constexpr Pair(int x = 0, int y = 0) : m_x{x}, m_y{y} {}
  constexpr int greater() const {
    return (m_x > m_y) ? m_x : m_y ; 
  }

  constexpr const int& getX() const { return m_x; }
  constexpr void reset() {
    m_x = 0;
    m_y = 0;
  }
};

constexpr Pair zero(){
  Pair p {1,2}; // --c constexpr constructor needed
  p.reset();    // --c constexpr reset needed
  return p;
  // return Pair{0 ,0};
}

int main(){
  Pair p1 {3,4}; //constexpr constructor wasnt necessary
  p1.reset(); // ok p1 isnt const
  std::cout << p1.getX() << "\n";

  Pair p2 { zero() }; // zero isnt called in constexpr context
  p2.reset();
  std::cout << p2.getX() << "\n";

  constexpr Pair p3 { zero() }; // zero is called in constexpr context --c
  // p3.reset(); // error p3 is implicitly const and reset isnt
  std::cout << p3.getX() << "\n";
  return 0;
}