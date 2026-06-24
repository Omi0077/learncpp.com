#include <iostream>

struct Employee{
  int id{};
  int age{};
  double wage{};
};

void printEmplyee(const Employee& e){
  std::cout << "const one\n";
  std::cout << "id: " << e.id << "\n" << "age: " << e.age << "\n" << "wage: " << e.wage << "\n";
}

void printEmplyee(Employee& e){
  std::cout << "id: " << e.id << "\n" << "age: " << e.age << "\n" << "wage: " << e.wage << "\n";
}

int main(){
  Employee e1 {1, 34 , 12000};
  printEmplyee(e1);

  // passing temproary objects

  // 1
  printEmplyee(Employee {2,23,10000});

  // 2
  printEmplyee({3,36, 5000}); // implicit conversion so may not be used where only explicit value is accepted

  // temp objects are evaluated as rvalue
  // so case 1 and 2 are using const reference overload

  return 0;
}