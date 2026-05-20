/*
 std::string_view provides read-only access to an existing string (a C-style string, a std::string, or another std::string_view) without making a copy. Read-only means that we can access and use the value being viewed, but we can not modify it.
*/

#include <iostream>

void printCstring(const char *s)
{
  std::cout << s << std::endl;
}

int main()
{
  std::string_view sv = "hello world";
  // sv accepts std::string, cstring, or another sv

  std::string ss{sv};
  // std::string ss = s;
  // std::string constructor that accepts std::string_view is marked explicit
  // thus, {} initialization works but not copy init..

  // but std::string cant be implicitly initialized by sv

  // when assign to sv it only changes what its viewing not the orignal string
  std::string s = "yo man";
  std::string_view s1 = s;
  std::cout << s << std::endl;
  std::cout << s1 << std::endl;
  s1 = "no man";
  std::cout << s << std::endl; // not changed
  std::cout << s1 << std::endl;

  using namespace std::string_literals;
  using namespace std::string_view_literals;
  // printCstring("haha"s);
  // printCstring("haha"sv); // these 2 dont work as func expects c string literal
  printCstring("haha");

  //unlike std::string, sv has full support for constexpr
  constexpr std::string_view s2 = "lost control";
  std::cout << s2 << std::endl;

  // constexpr std::string s3 = "lost control";
  // std::cout << s3 << std::endl;

  /*
    std::string_view: Lightweight, no allocation → constexpr ✓
    std::string: Dynamic allocation, complex lifetime → not constexpr (in most contexts)
  */

  return 0;
}