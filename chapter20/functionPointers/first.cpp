#include <iostream>

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
  // void(*fptr)(){foo};
  // fptr();
  // fptr = goo;
  // fptr();

  void (*const fptr)(){foo};
  fptr();
  // fptr = goo; // cannot be reseated
  fptr();

  return 0;
}