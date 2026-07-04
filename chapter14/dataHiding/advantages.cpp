#include <iostream>

// 2
// class Employee
// {
//   std::string m_name{"Joe"};
//   char m_firstInitial{'J'};

//   public:
//   void setName(std::string_view n){
//     m_name = n;
//     m_firstInitial = m_name.front();
//   }

//   void print(){
//     std::cout << "Employee name: " << m_name << " first initial: " << m_firstInitial << "\n";
//   }
// };

// 3
class Employee
{
  std::string m_name{"Joe"};

public:
  void setName(std::string_view n)
  {
    if (n == "")
      return;
    m_name = n;
  }

  char firstInitial() { return m_name.front(); }

  void print()
  {
    std::cout << "Employee name: " << m_name << " first initial: " << firstInitial() << "\n";
  }
};

int main()
{

  /*
  benefits of data hiding :-
  1. it makes classes easier to use, and reduces complexity
  2. it allows us to maintain class invariants
  3. it allows us to detect error and handle them easily
  4. it makes possible to change implementation without breaking existing code
  */

  // 1 - we dont need to understand how string_view is implemented
  std::string_view sv{"hello guys"};
  std::cout << sv.length() << "\n";

  // 2
  Employee e{};
  e.setName("Om shankar");
  e.print();

  // 3
  Employee e2{};
  e2.setName("");
  e2.print(); // UB - error
  // but since we are using public interface interface it can be easily handled

  return 0;
}