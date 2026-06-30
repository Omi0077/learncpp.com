#include <iostream>

class Person{
  std::string m_name{};

public:
  void setName(std::string_view name){
    m_name = name;
  }

  void kisses(const Person &p){
    std::cout << m_name << " kisses " << p.m_name << "\n"; // can access p.m_name
  }
};

int main(){

  Person p1{};
  p1.setName("Aman");

  Person p2{};
  p2.setName("Bablu");

  p1.kisses(p2);

  return 0;
}