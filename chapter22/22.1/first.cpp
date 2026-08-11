#include <iostream>

template <typename T>
class AutoPtr
{
  T *ptr_{};

public:
  AutoPtr(T *obj) : ptr_{obj} {}

  ~AutoPtr() { delete ptr_; }

  T &operator*() { return *ptr_; }
  T *operator->() { return ptr_; }
};

class Resource
{
public:
  Resource() { std::cout << "resource acquired\n"; }
  ~Resource() { std::cout << "resource destroyed\n"; }
};

int main(int argc, char *argv[])
{
  // without using our AutoPtr
  // Resource* res { new Resource{} }; // only prints resource acquired

  // with our AutoPtr class

  AutoPtr<Resource> res { new Resource{} }; // but there's a catch
  return 0;
}
