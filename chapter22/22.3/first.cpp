#include <iostream>
#include <assert.h>

template <typename T>
class AutoPtr3
{
  T *ptr_{};

public:
  AutoPtr3(T *ptr = nullptr) : ptr_{ptr} {}
  ~AutoPtr3() { delete ptr_; }

  // deep copy constructor
  AutoPtr3(const AutoPtr3 &source)
  {
    assert(source.ptr_);
    ptr_ = new T{};
    *ptr_ = *(source.ptr_);
  }

  // deep copy assignment
  AutoPtr3 &operator=(const AutoPtr3 &source)
  {
    assert(source.ptr_);
    if (&source == this)
    {
      return *this;
    }

    delete ptr_;

    ptr_ = new T{};
    *ptr_ = *(source.ptr_);

    return *this;
  }

  T &operator*() { return *ptr_; }
  T *operator->() { return ptr_; }
  bool isNull() { return ptr_ == nullptr; }
};

class Resource
{
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

AutoPtr3<Resource> generateResource()
{
  AutoPtr3 res{new Resource{}};
  return res;
}

int main()
{
  AutoPtr3<Resource> mainres{};
  mainres = generateResource();
  return 0;
}


/*
orignally this program prints -: 
Resource acquired
Resource acquired
Resource destroyed
Resource acquired
Resource destroyed
Resource destroyed

my output isnt same, cuz return value of generateResource is getting elided -:
Resource acquired
Resource acquired
Resource destroyed
Resource destroyed

lets talk about orignal one-:
1. first resource acquired inside generateResource , when res is init with dynamically allocated Resource.
2. second resource acquired is in return by value stmt when temporary object is copy constructed with res 
3. Res goes out of scope so resource destroyed
4. temporary object is assigned to mainres by copy assignment , resource acquired
5. temporary goes out of scope after expression resource destroyed
6. mainres goes out of scope resource destroyed

this ended up allocating three different objects.
*/