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
  Employee e1{1, 25};
  // e1.whatever is copy init from empty list, which performs value initialization
  // on class types it envokes default constructor

  Employee e2{};

  std::cout << e1 << "\n" << e2 << "\n";

  return 0;
}