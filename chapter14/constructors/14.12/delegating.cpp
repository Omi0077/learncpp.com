#include <iostream>

class Employee
{
  std::string m_name{"????"};
  int m_id{0};

public:
  Employee(std::string_view name)
      : Employee(name, 0)
  {
    std::cout << "lol\n";
  }
  Employee(std::string_view name, int id)
      : m_name{name}, m_id{id}
  {
    std::cout << "Employee " << m_name << " created\n";
  }
  void print(){
    std::cout << m_name << ' ' << m_id << '\n';
  }
};

int main()
{
  Employee e{"om shankar"};
  e.print();
  return 0;
}