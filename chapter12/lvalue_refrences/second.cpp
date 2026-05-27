#include <iostream>

int main(){
  static const int x{5};

  constexpr const int& ref{x};

  constexpr int y{ref};
  return 0;
}