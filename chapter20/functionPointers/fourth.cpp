#include <iostream>
#include <functional>

void foo()
{
  std::cout << "foo\n";
}

void goo()
{
  std::cout << "goo\n";
}

int main()
{
  // std::function<void()> fptr{foo};

  // fptr();

  // fptr = goo;
  // fptr();

  const std::function<void()> fptr{foo};

  fptr();

  // fptr = goo; // cannot be reseated
  fptr();

  // CTAD
  std::function fptr2 {goo};
  fptr2();

  return 0;
}