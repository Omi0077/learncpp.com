#include <iostream>

namespace Color
{
  enum Color
  {
    red,
    green,
    blue,
    white,
    black,
    grey,
    pink,
  };
}

namespace Job
{
  enum Job
  {
    white,
    grey,
    black,
  };
}

// enumerators get same scope as enum so they all pollute global namespace
// resulting in collisions

// to avoid naming collision use namespaces

int main(void)
{
  Color::Color hairColor{Color::white}; // error
  Color::Color shirtColor{Color::green};
  // Color eyeColor {yellow}; // error
  return 0;
}