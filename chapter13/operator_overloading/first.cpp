#include <iostream>
#include <optional>

// we can overload << and >> to handle our program defined type

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

// but lets first right some utils

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

int main(void)
{
  Color shirtColor{white};
  // std::cout << "shirt color is " << shirtColor << "\n"; // still prints integral value
  std::cout << "shirt color is " << getColorName(shirtColor) << "\n";

  // now take input a Color

  // Color hairColor{};
  // std::cout << "enter hair color :";
  // std::cin >> hairColor; //error >> doesnt know how to handle Color type

  // so instead

  // std::cout << "enter hair color (0:black, 1:blue...):";
  // int input{};
  // std::cin >> input;

  // if (input < 0 || input > 7)
  // {
  //   std::cout << "you entered invalid color\n";
  // }
  // else
  // {
  //   hairColor = static_cast<Color>(input);
  //   std::cout << "your hair color is " << getColorName(hairColor) << "\n";
  // }

  // but this method is too awkward
  // using function

  std::cout << "enter hair color :";
  std::string input{};
  std::cin >> input;

  std::optional<Color> hairColor = getColorFromString(input);
  if(!hairColor.has_value()){
    std::cout << "you entered invalid color\n";
  }
  else{
    std::cout << "your hair is " << getColorName(hairColor.value()) << "\n";
  }
  

  return 0;
}