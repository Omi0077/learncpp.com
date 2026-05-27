#include <iostream>
#include <string>

template <typename T>
bool isLvalue(T&){
  return true;
}

template <typename T>
bool isLvalue(T&&){
  return false;
}

#define TESTVALUE(expr) {std::cout<<#expr<<" is a "<<(isLvalue(expr) ? "Lvalue\n":"Rvalue\n");}

int main(){
  TESTVALUE(5);
  TESTVALUE(std::string("hello"));
  int x{10};
  TESTVALUE(x++);
  TESTVALUE(++x);

  return 0;
}