#include <iostream>

// this function will take precedence for args of int type
void print_int (int a){
  std::cout << a << "\n";
}

// void print_int (double a){
//   std::cout << a << "\n";
// }

void print_int(char a) = delete;

// we can delete all non matching overloads using templates

// this function will take precedence for args of other types
template <typename T>
void print_int(T a) = delete;

int main(){
  print_int(5);
  // print_int(5L);

  print_int('ABCDE'); // multichar is int

  print_int(50.0); // call to deleted
  return 0;
}