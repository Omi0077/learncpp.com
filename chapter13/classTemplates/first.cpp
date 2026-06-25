#include <iostream>

// template <typename T>
// struct Pair{
//   T first;
//   T second;
// };

struct Point{
  int first{};
  int second{};
};

template <typename T, typename U>
struct Pair
{
  T first{};
  U second{};
};

// void print(Pair<int> p){  // this works only for one type Pair<int>
//   std::cout << "[" << p.first << " " << p.second << "]\n";
// }

// template <typename T>
// void print(Pair<T, T> p)
// {
//   std::cout << "[" << p.first << " " << p.second << "]\n";
// }

// template <typename T, typename U>
// void print(Pair<T, U> p)
// {
//   std::cout << "[" << p.first << " " << p.second << "]\n";
// }

// making a function template work with multiple class types

template <typename T>
void print(T p)
{
  std::cout << "[" << p.first << " " << p.second << "]\n"; // will only compile if type has first and second menbers
}

int main()
{
  Pair<int, int> p1{1, 2};
  print(p1);

  Pair<double, double> p2{1.5, 3.3};
  print(p2);

  Pair<int, double> p3{5, 6.4};
  print(p3);

  print(Point{5,4});
  // print({5,4}); // this doesnt work as T cant be deduced for this 
  // its a template so template type deduction may not work with implicit conversion

  // auto pp = {5,4};
  // std::cout << typeid(pp).name() << "\n";
  // print(pp);

  std::pair<int,double> p4{5,7.5};
  print(p4); // works cuz std::pair has first and second members

  return 0;
}