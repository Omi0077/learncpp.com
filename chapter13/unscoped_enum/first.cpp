#include <iostream>

enum Color{
  red,
  green,
  blue,
  white,
  black,
  grey,
  pink,
};

int main(void){
  Color hairColor {white};
  Color shirtColor {green};
  // Color eyeColor {yellow}; // error
  return 0;
}