#include <iostream>

int initX();
int initY();

int x {initX()};
int y {initY()};

int initX()
{
  return y;  // here y isnt initialized yet
}

int initY()
{
  return 69;
}

int main()
{
  std::cout << x << " " << y << std::endl;
  return 0;
}