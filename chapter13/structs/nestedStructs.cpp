#include <iostream>

struct Company{
// private:
  struct Employee{
    std::string name{};
    int age{};
    double wage{};
  };
// public:
  int numberOfEmployees{};
  Employee ceo{};
};

int main(){
  Company c{10,{"om", 20, 10000.0}};

  Company::Employee e{};
  e.name = "lol";

  c = {c.numberOfEmployees, e};
  return 0;
}