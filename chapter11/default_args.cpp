#include <iostream>

// forward declaration
void print_sum(int a = 50, int b = 10);

void print_sum(int a, double b = 25.5);

int main(){
  print_sum(5,4);
  // print_sum(5);  // default agrs are inserted by compiler at site of function call
  // print_sum(,40) // we cannot skip a default parameter in cpp

  // since overloading
  // print_sum(40); // matches both 


// default args dont work for functions called through function pointers
  void (*ptr)(int,double) = print_sum;
  ptr(50,40);
}

// this will cause error as default args cant be redeclared
// and we wont be able to utilise default if not provided in forward dec..
// so just remove it from definition
void print_sum(int a,int b){
  std::cout << a+b << "\n";
}

void print_sum(int a,double b){
  std::cout << a+b << " double one\n";
}