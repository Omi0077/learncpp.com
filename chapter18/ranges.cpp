#include <iostream>
#include <array>
#include <algorithm>

void doubleNum(int &i)
{
  i *= 2;
}

template <typename T, std::size_t S>
void print(std::array<T, S> arr)
{
  for (auto i : arr)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::array arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print(arr);

  std::for_each(arr.begin(), arr.end(), doubleNum);
  print(arr);

  std::ranges::for_each(arr, doubleNum);
  print(arr);
  return 0;
}