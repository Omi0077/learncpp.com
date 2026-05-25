#include <iostream>

// template <int N>
// void printPositive(){
//   static_assert(N >= 0, "negative value not accepted\n");

//   std::cout << N << "\n";
// }

// template <char N>
// void printPositive(){
//   static_assert(N >= 0, "negative value not accepted\n");

//   std::cout << N << "\n";
// }

// one way to overcome this is using auto instead of having different overloads

template <auto N>
void printPositive(){
  static_assert(N >= 0, "negative value not accepted\n");

  std::cout << N << "\n";
}

int main(){
  // printPositive<5>();
  // leads to ambiguous as algorithm to match template overloads arent as complex as
  // algorithm to match function overloads.
  // printPositive<'c'>()
  // this is also ambiguous

  // now calling will not lead to ambiguous matches
  printPositive<5>();
  printPositive<'A'>();
  // bcs this instantiates two different functions , template matching doesnt case problem 
  // as there is only one template
  return 0;
}