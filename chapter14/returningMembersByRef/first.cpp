#include <iostream>

class Employee
{
  std::string m_name{};

public:
  void setName(std::string_view name){m_name = name;}
  const std::string &getName() { return m_name; }
};

Employee createEmployee(std::string_view name){
  Employee e;
  e.setName(name);
  return e;
}

int main()
{
  Employee e{};
  e.setName("Aman");
  const std::string &ref1{e.getName()}; // implicit object is lvalue
  std::cout << ref1 << "\n";

  const std::string &ref2 { createEmployee("Bablu").getName() }; // imlicit object is rvalue
  // ref2 left dangling
  std::cout << ref2 << "\n"; // UB

  const std::string non_ref { createEmployee("Bablu").getName() }; // imlicit object is rvalue
  // it gets copied in an independent variable
  std::cout << non_ref << "\n"; // UB

  return 0;
}