#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

class Monster {
public:
  enum Type {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    maxMonsterTypes,
  };

  Monster(Type type, std::string_view name, std::string_view roar,
          int hitPoints)
      : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints} {}

  constexpr std::string_view getTypeString() const {
    // returning const std::string& makes a temporary std::string and returns
    // its reference
    switch (m_type) {
    case dragon:
      return "dragon";
    case goblin:
      return "goblin";
    case ogre:
      return "ogre";
    case orc:
      return "orc";
    case skeleton:
      return "skeleton";
    case troll:
      return "troll";
    case vampire:
      return "vampire";
    case zombie:
      return "zombie";
    default:
      return "???";
    }
  }

  void print() const {
    std::cout << m_name << "[" << m_hitPoints << "] the " << getTypeString() << ' ';
    if (m_hitPoints < 1)
      std::cout << "is dead.\n";
    else
      std::cout << m_roar << ".\n";
  }

private:
  Type m_type{};
  std::string m_name{"???"};
  std::string m_roar{"????"};
  int m_hitPoints;
};

namespace MonsterGenerator {

std::string_view getName(int i) {
  switch (i) {
  case 0:
    return "Balgor";
  case 1:
    return "Vorgath";
  case 2:
    return "Skorzen";
  case 3:
    return "Xylos";
  case 4:
    return "Malakor";
  case 5:
    return "Krazor";
  default:
    return "???";
  }
}

std::string_view getRoar(int i) {
  switch (i) {
  case 0:
    return "*clatters*";
  case 1:
    return "*crunches*";
  case 2:
    return "*hums*";
  case 3:
    return "*hisses*";
  case 4:
    return "*snaps*";
  case 5:
    return "*scrapes*";
  default:
    return "???";
  }
}

Monster generate() {
  return Monster{static_cast<Monster::Type>(Random::get(0, 7)),
                 getName(Random::get(0, 5)), getRoar(Random::get(0, 5)),
                 Random::get(1, 100)};
}

} // namespace MonsterGenerator

int main() {
  Monster m{MonsterGenerator::generate()};
  m.print();

  return 0;
}