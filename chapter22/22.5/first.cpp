#include <iostream>
#include <memory>

class Resource
{
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::ostream &operator<<(std::ostream &out, const Resource &res)
{
  out << "I am resource\n";
  return out;
}

void testResource(const Resource *res) // this function is agnostic of how resource is managed by caller
{
  if (res)
  {
    std::cout << *res;
  }
  else
  {
    std::cout << "no resource\n";
  }
}

int main()
{
  auto res{std::make_unique<Resource>()};

  testResource(res.get());
  // testResource(res->); // this operator return pointer(as overloaded) ,
                       // but orignaly takes a pointer derefs it and calls a member
  return 0;
}