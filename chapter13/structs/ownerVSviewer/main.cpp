#include <iostream>

struct Owner{
  std::string name{};
};

struct Viewer{
  std::string_view name{};
};

std::string getName(){
  std::cout << "enter name: ";
  std::string name{};
  std::cin >> name;
  return name;
}

int main(){

  Owner o{getName()};
  Viewer v{getName()};

  for(int i{0}; i<100; i++){
    std::string s{"hello"};
  }

  std::cout << "owner name: " << o.name << "\n";
  std::cout << "viewer name: " << v.name << "\n";

  return 0;
}