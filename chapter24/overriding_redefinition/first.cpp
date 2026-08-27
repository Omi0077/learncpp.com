#include <iostream>

class Base {
  public:
  void num(int x) { std::cout << "Base::num(int)\n"; }
  void num(double x) { std::cout << "Base::num(double)\n"; }
};

class Derived : public Base {
private:
  void num(double x) { std::cout << "Derived::num(double)\n"; } // this aint best match nut still resolves
  // this is redefinition/overriding
};
int main() { 
  Base b;
  b.num(20);

  Derived d;
  // d.num(20);

  return 0; }