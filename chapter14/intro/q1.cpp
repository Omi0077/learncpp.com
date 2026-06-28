#include <iostream>

enum AnimalType
{
  cat,
  dog,
  chicken,
  snake,
};

constexpr std::string_view animalName(const AnimalType animal)
{
  switch (animal)
  {
  case cat:
    return "cat";
  case dog:
    return "dog";
  case chicken:
    return "chicken";
    case snake:
    return "snake";
  default:
    return "???";
  }
}

constexpr int numLegs(const AnimalType animal)
{
  switch (animal)
  {
  case cat:
    return 4;
  case dog:
    return 4;
  case chicken:
    return 2;
  case snake: return 0;
  default:
    return 0;
  }
}

int main()
{
  constexpr AnimalType animal{snake};
  std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

  return 0;
}