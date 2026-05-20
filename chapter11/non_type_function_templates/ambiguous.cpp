#include <iostream>

template <int N>
void printPositive(){
  static_assert(N >= 0, "negative value not accepted\n");

  std::cout << N << "\n";
}

template <char N>
void printPositive(){
  static_assert(N >= 0, "negative value not accepted\n");

  std::cout << N << "\n";
}

int main(){
  printPositive<5>();
  // leads to ambiguous as algorithm to match template overloads arent as complex as
  // algorithm to match function overloads.
  printPositive<'c'>()
  // this is also ambiguous
  return 0;
}