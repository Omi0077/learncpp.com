#include <iostream>
#include <typeinfo>

int main()
{
  std::cout << typeid(3.1f+3.5).name() << "\n"; 
  short a = 5;
  short b = 6;
  std::cout << typeid(a+b).name() << "\n"; 

  unsigned int a2 = 1;
  signed int b2 = -5;

  std::cout << typeid(a2 + b2).name() << a2+b2 << "\n"; 

  if(-5 < 11u) std::cout << "hello\n" ;
  else std::cout << "faakee\n";

  return 0;
}