#include <iostream>
#include <algorithm>

int main()
{
  std::array<std::string_view, 6> arr{"apple", "banana", "walnut", "lemon", "whitenut", "bluberry"};

  auto comparator // stored the lambda definition in lambda variable
  {
    [](std::string_view str)
    { return str.find("nut") != std::string_view::npos; }
  };

  auto found{std::find_if(arr.begin(), arr.end(), comparator)};

  int count{static_cast<int>(std::count_if(arr.begin(), arr.end(),comparator))};

  if (found != arr.end())
  {
    std::cout << "found first nut in : " << *found << '\n';
  }

  std::cout << "total nuts found: " << count << '\n';
  return 0;
}