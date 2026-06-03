#include <iostream>
#include <optional>

// in this file we will teach << and >> to handle Color

enum Color
{
  black,
  blue,
  yellow,
  green,
  red,
  white,
  pink,
  orange,
};

constexpr std::string_view getColorName(Color color)
{
  switch (color)
  { // we can switch on integral types and enums
  case black:
    return "black";
  case blue:
    return "blue";
  case yellow:
    return "yellow";
  case green:
    return "green";
  case red:
    return "red";
  case white:
    return "white";
  case pink:
    return "pink";
  case orange:
    return "orange";
  default:
    return "????";
  }
}
 
constexpr std::optional<Color> getColorFromString(std::string_view sv){
  if(sv == "black") return black;
  if(sv == "blue") return blue;
  if(sv == "yellow") return yellow;
  if(sv == "green") return green;
  if(sv == "red") return red;
  if(sv == "white") return white;
  if(sv == "pink") return pink;
  if(sv == "orange") return orange;

  return std::nullopt;
}

// << return its left operand which is std::cout which has type std::ostream
std::ostream& operator<<(std::ostream& out, Color color){
  // out << getColorName(color);
  // return out;
  // or
  return out << getColorName(color);
}

std::istream& operator>>(std::istream& in, Color& color){
  std::string s{};
  in >> s;

  std::optional<Color> temp = getColorFromString(s);

  if(!temp.has_value()){
    in.setstate(std::ios_base::failbit);
    return in;
  }

  // color = temp.value();
  color = *temp;
  return in;
}

int main(void){
  Color shirtColor {};
  std::cout << "enter your shirt color: ";
  std::cin >> shirtColor;
  std::cout << "your shirt color is " << shirtColor << "\n";
  return 0;
}