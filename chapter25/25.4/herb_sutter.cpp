#include <iostream>
#include <memory>

class A {
protected:
  ~A() { std::cout << "~A() called\n"; }
};

class B : public A {
  int *m_arr{nullptr};

public:
  B(int length) : m_arr{new int[length]} {}
  virtual ~B() {
    std::cout << "~B() called\n";
    delete[] m_arr;
  }
};

int main() {
  
  std::unique_ptr<A> b {std::make_unique<B>(100)}; // memory leak without public+virtual destructor
  std::shared_ptr<A> a {std::make_shared<B>(100)}; // this works as sp's control block captures 
                                                             // concrete type at construction

  return 0;
}