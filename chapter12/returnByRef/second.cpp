#include <iostream>

int& max(int& x, int& y){
  return (x>y) ? x : y;
}

int main(){
  int x{8};
  int y{4};

  max(x,y) = 20;

  std::cout << x <<" " << y;
}