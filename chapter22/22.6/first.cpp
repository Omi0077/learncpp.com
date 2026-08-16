#include <iostream>
#include <memory>

class Resource
{
public:
  Resource() { std::cout << "Resource created\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
  // Resource *res{new Resource{}};
  // std::shared_ptr<Resource> ptr1 {res};
  // {
  //   std::shared_ptr<Resource> ptr2{res};
  // }

  auto ptr1 {std::make_shared<Resource>()};
  auto ptr2 {ptr1}; // must use copy assignment/ctor, otherwise they wont be aware of each other
  return 0;
}