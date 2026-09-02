#include <iostream>

class Base {
  public:
  virtual void print(int x){
    std::cout << x << " Base\n";
  }
};

class Derived : public Base {
  public:
  void print(double x) override {} // for overriding signature has to be same, thus is hiding not overriding
};
 
int main(){
  return 0;
}