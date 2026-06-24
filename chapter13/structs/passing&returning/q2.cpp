#include <iostream>
#include <type_traits>

struct Fraction{
  int num{};
  int den{};
};

Fraction readFraction(){
  Fraction temp{};

  std::cout << "Enter numerator: ";
  std::cin  >> temp.num;
  std::cout << "Enter denominator: ";
  std::cin  >> temp.den;

  return temp;
}

void printFraction(const Fraction& f){
  std::cout << "Numerator: " << f.num << "\n";
  std::cout << "Denominator: " << f.den << "\n";
}

// consteval Fraction multiply(const Fraction& f1, const Fraction& f2){
//   return Fraction {f1.num*f2.num, f1.den*f2.den};
// }

constexpr Fraction multiply(const Fraction& f1, const Fraction& f2){
  if (std::is_constant_evaluated()) {
    // std::cout << "used in compile time context\n";
    return {};
  }
  return Fraction {f1.num*f2.num, f1.den*f2.den};
}

int main(){
  Fraction f1{readFraction()};
  Fraction f2{readFraction()};

  constexpr Fraction f3{3,4};
  constexpr Fraction f4{4,3};

  // constexpr Fraction product {multiply(f1,f2)}; // f1 and f2 cant be used
  constexpr Fraction product {multiply(f3,f4)};
  printFraction(product);

  printFraction(multiply(f1,f2));
  // printFraction(multiply(f3,f4));
  
  return 0;
}