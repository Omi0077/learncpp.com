#include <iostream>
#include <assert.h>

template <typename T>
class AutoPtr
{
  T *ptr_{};

public:
  AutoPtr(T *obj) : ptr_{obj} {}

  // copy constructor that implements move semantics
  AutoPtr(AutoPtr &other)
  {
    assert(other.ptr_);
    ptr_ = other.ptr_;
    other.ptr_ = nullptr; // source no longer owns the pointer

    std::cout << "resouce transfered\n";
  }

  ~AutoPtr() { delete ptr_; }

  T &operator*() { return *ptr_; }
  T *operator->() { return ptr_; }
  bool isNull() { return ptr_ == nullptr; }

  AutoPtr &operator=(AutoPtr &other)
  {
    assert(other.ptr_);

    if (&other == this)
    {
      return *this;
    }

    delete ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;

    std::cout << "resouce transfered\n";

    return *this;
  }
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

  AutoPtr<Resource> res{new Resource{}}; // but there's a catch

  // default copy constructor and operator= does shallow copy
  // leading to both AutoPtr objs pointing to same resource obj
  // and when one goes out of scope AutoPtr's destructor frees the Resource
  // leaving the other AutoPtr's inner T* ptr_ dangling
  // deleting it again is UB or crash

  // AutoPtr res2{res};
  // prints
  /*
  resource acquired
  resource destroyed
  resource destroyed
  free(): double free detected in tcache 2
  Aborted (core dumped)
  */

  // to solve this we have a few options
  // 1. explicitly define and delete copy constructor and operator=, to make sure no copy is made
  //    but then how will we return from function by value
  // 2. perform deep copy, tadah its working but its expensive
  // 3. we should apply move semantics instead of copy,
  //    i.e instead of copying the pointer we move the ownership of pointer from source to destination

  AutoPtr<Resource> res2 {nullptr};
  std::cout << "res 1 is " << ((res.isNull()) ? "null\n" : "not null\n");
  std::cout << "res 2 is " << ((res2.isNull()) ? "null\n" : "not null\n");

  res2 = res;

  std::cout << "res 1 is " << ((res.isNull()) ? "null\n" : "not null\n");
  std::cout << "res 2 is " << ((res2.isNull()) ? "null\n" : "not null\n");
  return 0;
}
