#include <iostream>
#include <array>
#include <mdspan>

template <typename T, std::size_t row, std::size_t col>
using Array2d = std::array<T, row * col>;

int main()
{
  Array2d<int, 3, 2> arr{1, 2, 3, 1, 2, 3};
  std::mdspan twoDView{arr.data(), 3, 2}; // c++23
  std::size_t rows{twoDView.extents().extent(0)};
  std::size_t cols{twoDView.extents().extent(1)};

  twoDView[0, 1] = 69;

  for (std::size_t row{0}; row < rows; row++)
  {
    for (std::size_t col{0}; col < cols; col++)
    {
      std::cout << twoDView[row, col] << ' ';
    }
    std::cout << '\n';
  }

  for(auto i: arr){std::cout << i << ' ';}  //value changed in orignal array too
  return 0;
}