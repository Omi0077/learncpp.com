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

  // move constructor
  AutoPtr3(AutoPtr3 &&source) noexcept : ptr_{source.ptr_}
  {
    source.ptr_ = nullptr;
  }

  AutoPtr3 &operator=(AutoPtr3 &&source) noexcept
  {
    if (&source == this)
    {
      return *this;
    }

    delete ptr_;

    ptr_ = source.ptr_;
    source.ptr_ = nullptr;

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
  return res; // invokes move constructor
  // cuz automatic local l-values returned by values can be moved
}

int main()
{
  AutoPtr3<Resource> mainres{};
  mainres = generateResource(); // this now invokes move assignment
  return 0;
}

/*
this now just prints :-
Resource acquired
Resource destroyed

1. resource acquired when res initialized in generateResouce : resource acquired
2. return res invokes move constructor so no object creation
3. temporary object agin moved into mainres so no new object
4. mainres goes out of scope : resource destroyed
*/