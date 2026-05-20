/*
std::string_view is a viewer not an owner , it has no control over object its viewing

whereas std::string is an owner
*/

#include <iostream>
#include <vector>

// std::string_view is best for read-only function parameters
void printString(std::string_view s)
{
  std::cout << s << std::endl;
}
// prefer sv over const std::string& as parameters

int main()
{
  std::string s = "gg";
  std::string_view sv = s;
  std::cout << s << " " << sv << std::endl;
  s = "ll";
  // sv was viewing to s but s changed its value so sv now view "ll"
  // this may cause UB as changing underlying string ivalidates its viewrs 
  std::cout << s << " " << sv << std::endl;

  sv = s; // this re-validates sv

  using namespace std::string_literals;
  
  std::string_view sv2{"yo"s};

  // dont init with std::string literals
  // and use std::string objects only when object outlives sv

  // Force some memory operations to potentially overwrite the freed memory
  std::string other1 = "some other string that might reuse memory";
  std::string other2 = "another string";
  std::vector<int> vec(1000, 42);

  std::cout << sv2 << std::endl; // this may cause UB
  // std::terminate();

  // if return type of a function is sv then only return cstring as they live for whole program

  //########## view-modifying methods ########################################################################

  std::string s2 = "om shankar";
  std::string_view sv3 = s2;
  std::cout << s2 << " " << sv3 << std::endl;

  sv3.remove_prefix(2);
  sv3.remove_suffix(4);
  std::cout << s2 << " " << sv3 << std::endl;
  /*Unlike real curtains, once remove_prefix() and remove_suffix() have been called, the only way to reset the view is by reassigning the source string to it again.*/

  /*
  A C-style string literal and a std::string are always null-terminated.
  A std::string_view may or may not be null-terminated.
  */
 
}