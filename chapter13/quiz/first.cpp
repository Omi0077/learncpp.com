#include <iostream>

enum class MonsterType
{
  ogre,
  dragon,
  orc,
  giant,
  spider,
  slime,
};

std::string_view getMonsterType(const MonsterType m)
{
  using enum MonsterType;

  switch (m)
  {
  case ogre:
    return "ogre";
  case dragon:
    return "dragon";
  case orc:
    return "orc";
  case giant:
    return "giant";
  case spider:
    return "spider";
  case slime:
    return "slime";
  default:
    return "???";
  }
}

struct Monster
{
  MonsterType monsterType{MonsterType::spider};
  std::string name{};
  int health{10};
};

void printMonster(const Monster &m)
{
  std::cout << "This " << getMonsterType(m.monsterType) << " is named " << m.name << " and has "<< m.health << " health\n";
}

int main()
{
  Monster m1{MonsterType::ogre, "Torg", 145};
  Monster m2{MonsterType::slime, "Blurp", 23};

  printMonster(m1);
  printMonster(m2);

  return 0;
}