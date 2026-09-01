#include <iostream>

class A {
public:
  virtual ~A() { std::cout << "~A() called\n"; }
};

class B : public A {
  int *m_arr{nullptr};

public:
  B(int length) : m_arr{new int[length]} {}
  ~B() {
    std::cout << "~B() called\n";
    delete[] m_arr;
  }
};

int main() {
  B* b { new B{100} };
  // delete b;

  A* a {b};

  delete a; // now ~A() is virtual

  return 0;
}