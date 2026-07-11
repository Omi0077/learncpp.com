#include <iostream>

class Employee
{
public:
  // class EmployeePrinter
  // {
  // public:
  //   void print(const Employee &e) const
  //   // Printer can't access Employee's `this` pointer
  //   // so we can't print m_name and m_id directly
  //   // Instead, we have to pass in an Employee object to use
  //   // Because Printer is a member of Employee,
  //   // we can access private members e.m_name and e.m_id directly
  //   {
  //     std::cout << "[" << e.m_id << "] " << e.m_name << " has " << e.m_wage << " salary\n";
  //   }
  // };

  class EmployeePrinter;

  using IdType = int;

private:
  std::string m_name{};
  IdType m_id{};
  double m_wage{};

public:
  Employee(std::string name, IdType id, double wage)
      : m_name{name}, m_id{id}, m_wage{wage} {}
};

class Employee::EmployeePrinter
  {
  public:
    void print(const Employee &e) const
    // Printer can't access Employee's `this` pointer
    // so we can't print m_name and m_id directly
    // Instead, we have to pass in an Employee object to use
    // Because Printer is a member of Employee,
    // we can access private members e.m_name and e.m_id directly
    {
      std::cout << "[" << e.m_id << "] " << e.m_name << " has " << e.m_wage << " salary\n";
    }
  };

int main()
{
  Employee e1{"chaman", 20, 12000.00};
  Employee::EmployeePrinter p{};
  p.print(e1);

  // iterators are defined as nested classes
  return 0;
}