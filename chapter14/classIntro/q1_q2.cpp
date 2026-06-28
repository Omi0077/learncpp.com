#include <iostream>

struct IntPair{
  int first{};
  int second{};

  void print(){
    std::cout << "[" << first <<", " << second << "]\n";
  }

  bool isEqual(IntPair p){
    return (first == p.first && second == p.second);
  }
};

int main(){

  IntPair p{2,1};
  p.print();

  IntPair p2{2,1};
  p2.print();

  std::cout << std::boolalpha << "p == p2 : " << p.isEqual(p2) << "\n"; 

  return 0;
}