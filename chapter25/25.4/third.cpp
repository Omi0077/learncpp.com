#include <iostream>
#include <memory>

class A {
public:
  virtual ~A() { std::cout << "~A() called\n"; }
};

class B final : public A {
  int *m_arr{nullptr};

public:
  B(int length) : m_arr{new int[length]} {}
  virtual ~B() {
    std::cout << "~B() called\n";
    delete[] m_arr;
  }
};

int main() {
  
  std::unique_ptr<A> b {std::make_unique<B>(100)}; // memory leak without virtual base destructor

  return 0;
}