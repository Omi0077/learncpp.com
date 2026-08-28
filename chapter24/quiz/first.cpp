#include <iostream>

class A {
protected:
  int x_;

public:
  A(int x) : x_{x} {}

  void print() { std::cout << "A " << x_ << '\n'; }
};

class B : public A {
public:
  B(int x) : A{x} {}

  void print() { std::cout << "B " << x_ << '\n'; }
};

class C : public B {
public:
  C(int x) : B{x} {}

  void print() { std::cout << "C " << x_ << '\n'; }
};

int main() { 
  A a(10);
  a.print();

  B b(10);
  b.print();

  C c(10);
  c.print();
  
  return 0; }