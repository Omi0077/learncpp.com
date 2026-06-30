#include <iostream>

struct Date{
  int day{};
  int month{};
  int year{};

  void print() const{
    std::cout << day << "/" << month << "/" << year << "\n";
  }

  void incrementDay(){
    ++day;
  }
};

void doSomething1(const Date &d){
  // here d is const regardless of orignal object
  d.print();
}

void doSomething2(const Date &d){
  // here d is const regardless of orignal object
  d.incrementDay(); // error
}

int main(){

  const Date d1 {5,12,2009};
  d1.print();

  Date d2 {10,10,1986};
  d2.incrementDay();
  d2.print();

  return 0;
}