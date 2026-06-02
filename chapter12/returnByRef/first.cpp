#include <iostream>

// const std::string& getName(){
//   static std::string name = "omi";
//   return name;
// }

// lifetime of temporary objects arent extended across functions
const int& getInt(){
  // static std::string name = "omi";
  return 5;
}

// its okay for an rvalue passed by const ref to be returned by const ref
const int& getInt(const int& x){
  return x;
}

int main(){
  // std::cout << "age is " << getInt();
  std::cout << "age is " << getInt(10);
  return 0;
}


// for returning by reference/address main rule of thumb is that object being returned by reference/address must outlive the function returning it. 