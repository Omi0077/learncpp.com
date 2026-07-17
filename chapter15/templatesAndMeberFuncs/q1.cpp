#include <iostream>

template <typename T, typename U, typename V> class Triad {
  T m_first{};
  U m_second{};
  V m_third{};

public:
  Triad(const T &first, const U &second, const V &thrid)
      : m_first{first}, m_second{second}, m_third{thrid} {}

  T getFirst() const { return m_first; }
  U getSecond() const { return m_second; }
  U getThird() const { return m_third; }

  void setFirst(const T &first) { m_first = first; }
  void setSecond(const U &second) { m_second = second; }
  void setThird(const V &third) { m_third = third; }

  void print() const;
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const {
  std::cout << "[" << m_first << ", " << m_second << ", " << m_third << "]\n";
}

int main() {
  Triad<int, int, int> t1{1, 2, 3};
  t1.print();
  std::cout << t1.getFirst() << '\n';

  using namespace std::literals::string_literals;
  const Triad t2{1, 2.3, "Hello"s};
  t2.print();

  return 0;
}