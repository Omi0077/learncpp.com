#include <iostream>
#include <array>

template <typename T, std::size_t row, std::size_t col>
using Array2d = std::array<std::array<T, col>, row>;

int main()
{
  Array2d<int, 3, 4> matrix3_4{std::array{1, 2, 3, 4}, // deduction works only with > c++20
                               std::array{1, 2, 3, 4},
                               std::array{1, 2, 3, 4}};

  for (int i{}; i < matrix3_4.size(); i++)
  {
    for (int j{}; j < matrix3_4[i].size(); j++)
    {
      std::cout << matrix3_4[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}