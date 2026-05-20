#include <iostream>

template <typename T>
void printIDAndValue(T value){
  static int ID {0};
  std::cout << "ID: " << ++ID << " value: " << value << "\n"; 
}

// each instantiaded function overload will have different static variable

int main(){
  printIDAndValue(12);
  printIDAndValue(15);
  printIDAndValue(17);
  printIDAndValue(17.55);
  printIDAndValue(14.35);
  printIDAndValue(false);

  return 0;
}