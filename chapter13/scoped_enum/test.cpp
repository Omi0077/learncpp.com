#include <iostream>

enum class Animal
{
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck,
};

std::string_view getAnimalName(Animal animal)
{
  using enum Animal;

  switch (animal)
  {
  case pig:
    return "pig";
  case chicken:
    return "chicken";
  case goat:
    return "goat";
  case cat:
    return "cat";
  case dog:
    return "dog";
  case duck:
    return "duck";
  default:
    return "???";
  }
}

void printNumberOfLegs(Animal animal)
{
  using enum Animal;

  switch (animal)
  {
  case pig:
    std::cout << 4 << "\n";
    break;
  case chicken:
    std::cout << 2 << "\n";
    break;
  case goat:
    std::cout << 4 << "\n";
    break;
  case cat:
    std::cout << 4 << "\n";
    break;
  case dog:
    std::cout << 4 << "\n";
    break;
  case duck:
    std::cout << 2 << "\n";
    break;
  default:
    std::cout << -1 << "\n";
  }
}

int main(){
  Animal animal1 = Animal::cat;
  Animal animal2 = Animal::chicken;

  Animal animal3{4}; // can list init without specifying base type

  std::cout << getAnimalName(animal1) << "\n";

  printNumberOfLegs(animal1);
  printNumberOfLegs(animal3);

  return 0;
}

/*
enum class doenst implicitly converts to integer values
enum class has its own scope for its enumerators
*/