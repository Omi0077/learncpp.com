#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector v{1, 2, 3, 4, 5, 6};
  for (auto i : std::views::reverse(v))
    std::cout << i << '\n';
  return 0;
}