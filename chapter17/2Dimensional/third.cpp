#include <iostream>
#include <array>

template <typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row * Col>;

template <typename T, std::size_t Row, std::size_t Col>
class Array2dView
{
private:
  std::reference_wrapper<ArrayFlat2d<T, Row, Col>> m_arr{};

public:
  Array2dView(ArrayFlat2d<T, Row, Col> &arr) : m_arr{arr} {}

  int rows() { return static_cast<int>(Row); }
  int cols() { return static_cast<int>(Col); }
  int length() { return static_cast<int>(Row * Col); }

  //[]
  T &operator[](int i) { return m_arr.get()[static_cast<std::size_t>(i)]; }
  const T &operator[](int i) const { return m_arr.get()[static_cast<std::size_t>(i)]; };

  //[row,col] only in c++23 >
  T &operator[](int row, int col)
  {
    return m_arr.get()[static_cast<std::size_t>(row * cols() + col)];
  }
  const T &operator[](int row, int col) const
  {
    return m_arr.get()[static_cast<std::size_t>(row * cols() + col)];
  }

  //(row,col) for standard below c++23
  T &operator()(int row, int col)
  {
    return m_arr.get()[static_cast<std::size_t>(row * cols() + col)];
  }
  const T &operator()(int row, int col) const
  {
    return m_arr.get()[static_cast<std::size_t>(row * cols() + col)];
  }
};

int main()
{
  ArrayFlat2d<int, 3, 3> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Array2dView<int, 3, 3> view{arr};

  std::cout << view[3] << '\n';

  for (int i{}; i < view.rows(); i++)
  {
    for(int j{}; j<view.cols(); j++){
      std::cout << view[i,j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}