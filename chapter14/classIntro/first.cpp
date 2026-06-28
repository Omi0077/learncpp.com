#include <iostream>

struct Date{
  int day{};
  int month{};
  int year{};

  void print(int day){
    /*
    note: in tutorial it said any member identifier which is not prefixed with . operator
    get associated with the implicit object.
    but in this case even though day is a member identifier it didnt get associated with implict object

    my guess?
    it might have been shadowed by day parameter.

    */
    std::cout << day << "/" << month << "/" << year << "\n";
  }

  void print(std::string_view prefix){
    std::cout << prefix << " " << day << "/" << month << "/" << year << "\n";
  }
};

// member variables and functions can be defined in any order 
// but dont use a data member in default initializer of another data member : causes UB

struct Foo{
  int z() { return m_data; }
  int x() { return y(); }

  int m_data{y()};
  int y(){return 5;}
};

// this works but 

// this doesnt cuz it uses a data member before its utilised so it will compile 
// but cause UB

struct Bad{
  int m_bad1{m_bad};
  int m_bad2{fcn()}; // these 2 dont cause error but use a data member that isnt init yet

  int m_bad{5};
  int fcn(){return m_bad;}
};

int main(){
  Date d1{12,5,2025};
  d1.print(200);
  d1.print("Date: ");

  Bad b{};
  std::cout << b.m_bad1 << "\n";
  std::cout << b.m_bad2 << "\n";
  // std::cout << b.m_bad << "\n";
  return 0;
}