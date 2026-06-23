#include <iostream>

struct Employee{
  int id{};
  int age{};
  double wage{};
  double whatever;
};

std::ostream& operator<<(std::ostream& out,Employee& e){

  out << e.id << " " << e.age << " " << e.wage << " " << e.whatever ;

  return out;
}

int main(){
  Employee e1 {1,34,50000.0};

  // e1 = {35}; // because of memberwise init this will set .id=35 .age=0 .wage=0.0 .whatever=0.0
  // to avoid this
  e1 = {e1.id, 35, e1.wage}; // we will have to provide every other value
  std::cout << e1 << "\n";


  // we can do same with designated init

  e1 = {.id{e1.id}, .age{e1.age+1}, .wage{e1.wage+5000.0}};
  std::cout << e1 << "\n";

  // any members not designated in this wil be value init
  e1 = {.age{e1.age+1}, .wage{e1.wage+5000.0}}; // id=0
  std::cout << e1 << "\n";


  // we can also assign a struct with another struct of same type

  // Employee e2 = e1; // copy init
  // Employee e2 (e1); // direct init
  Employee e2 {e1}; // direct-lisr init


  std::cout << e2 << "\n";

  return 0;
}