#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b){
  if(b == 0){
    return std::nullopt;
  }
  // return a/b;
  // implicit conversion to 
  return std::optional<int> {a/b};
}

int main(void){
  std::optional<int> result = divide(5,20);
  if(result.has_value()){
    std::cout << result.value() << "\n";
  }
  return 0;
}

// use const T* when its expesive to copy the type 