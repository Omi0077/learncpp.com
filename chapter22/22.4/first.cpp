#include <iostream>
#include <print>
#include <utility>

template <typename T>
void mvSwap(T &a, T &b) // dont need rvalue refrences as we want same functionality regardless of value category
{
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}

int main()
{
  int a{50}, b{100};
  std::println("a: {} , b: {}", a, b);

  mvSwap(a, b);
  std::println("a: {} , b: {}", a, b);

  return 0;
}