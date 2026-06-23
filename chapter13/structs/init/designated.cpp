#include <iostream>

struct Employee{
  int id{};
  int age{};
  double wage{40000.0};
  double whatever;
};

std::ostream& operator<<(std::ostream& out,Employee& e){

  out << e.id << " " << e.age << " " << e.wage << " " << e.whatever ;

  return out;
}

int main(){
  Employee e1{.id=5, .age{34}};
  // can use copy or list init for members
  // Employee e2{.id=5, .wage=4000.0, .age{34}}; // error as wage is out of order of declaration

  std::cout << e1 << "\n";

  return 0;
}