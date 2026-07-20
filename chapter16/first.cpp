#include <iostream>
#include <vector>

int main(){
  std::vector v{1,2,3,4,5};

  int index{3}; // non constexpr signed value
  std::cout << v[index] << '\n'; // gives sign conversion warning

  // so either convert to std::size_t evry time
  // or
  // create a std::size_t var just for indexing  (although it is unsafe)
  // or
  // v.data()[index]  // data return a pointer to underlying c-array 
  return 0;
}