#include <iostream>

class A {
  int a_{};
  int b_{};
  int c_{};

public:
  A(int a, int b, int c) : a_{a}, b_{b}, c_{c} {}
};

class B : public A {
  int z_{};

public:
  // B(int z) : z_{z} {}
  // so derived class must call a specfic base constructor if base has no default constructor
};