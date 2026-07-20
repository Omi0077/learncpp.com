#include <iostream>
#include <ranges>
#include <vector>

template <typename T>
constexpr bool isValueInArray(const std::vector<T> &arr, const T &value) {
  for (auto s : std::views::reverse(arr)) {
    if (s == value)
      return true;
  }
  return false;
}

int main() {
  using namespace std::literals::string_literals;
  std::vector names{"om"s,    "aman"s,    "hello"s,
                    "lolol"s, "Ronaldo"s, "Priyanshu"s};

  std::cout << std::boolalpha << isValueInArray(names, "Ronaldo"s) << '\n';
  std::cout << std::boolalpha << isValueInArray<std::string>(names, "Ronaldo")
            << '\n';
  return 0;
}
