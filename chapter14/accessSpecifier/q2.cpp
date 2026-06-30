#include <iostream>

class Point3d
{
  int m_x{};
  int m_y{};
  int m_z{};

public:
  void setValues(int x, int y, int z)
  {
    m_x = x;
    m_y = y;
    m_z = z;
  }

  void print() const
  {
    std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << "\n";
  }

  bool isEqual(const Point3d &p) const
  {
    return (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z);
  }
};

int main()
{

  Point3d p1;
  p1.setValues(1, 2, 3);
  p1.print();

  Point3d p2;
  p2.setValues(1, 2, 3);
  p2.print();

  std::cout << std::boolalpha << p1.isEqual(p2) << "\n";
  // std::cout << std::noboolalpha << p1.isEqual(p2) << "\n";

  return 0;
}