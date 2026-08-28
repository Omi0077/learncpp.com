#include <iostream>
#include <print>
#include <string>
#include <string_view>

#include "../../important/Random.h"

enum class SIGTYPE {
  MONSTER_DEAD,
  MONSTER_NOT_DEAD,
};

class Creature {
protected:
  std::string name_{};
  char symbol_{};
  int health_{};
  int dmgPerAttack_{};
  int gold_{};

public:
  Creature(std::string_view name, char symbol, int health, int dmgPerAttack,
           int gold)
      : name_{name}, symbol_{symbol}, health_{health},
        dmgPerAttack_{dmgPerAttack}, gold_{gold} {}

  // getters
  std::string getName() const { return name_; }
  char getSymbol() const { return symbol_; }
  int getHealth() const { return health_; }
  int getDPA() const { return dmgPerAttack_; }
  int getGold() const { return gold_; }

  void reduceHealth(int amount) { health_ -= amount; }
  bool isDead() const { return health_ <= 0; }
  void addGold(int amount) { gold_ += amount; }
};

class Player : public Creature {
  int level_{1};

public:
  Player(std::string_view name) : Creature{name, '@', 10, 1, 0} {}

  // getter
  int getLevel() const { return level_; }

  void levelUp() {
    ++level_;
    ++dmgPerAttack_;
  }
  bool hasWon() const { return level_ >= 20; }
};

class Monster : public Creature {
public:
  enum Type {
    dragon,
    orc,
    slime,
    maxTypes,
  };

  Monster(Type type) : Creature{monsterData[type]} {}

  static Monster getRandomMonster() {
    return Monster{static_cast<Type>(Random::get(0, maxTypes - 1))};
  }

private:
  static inline Creature monsterData[maxTypes]{
      Creature{"dragon", 'D', 20, 4, 100},
      Creature{"orc", 'o', 4, 2, 25},
      Creature{"slime", 's', 1, 1, 10},
  };
};

void attackMonster(Player &p, Monster &m) {

  // check if player is already dead
  if (p.isDead())
    return;

  m.reduceHealth(p.getDPA());
  std::println("You hit the {} for {} damage.", m.getName(), p.getDPA());

  // check if momster died
  if (m.isDead()) {
    std::println("You killed the {}.", m.getName());
    // level up
    p.levelUp();
    std::println("You are now level {}.", p.getLevel());
    // gain gold
    p.addGold(m.getGold());
    std::println("You found {} gold.", m.getGold());
  }
}

void attackPlayer(Monster &m, Player &p) {

  // check if monster is already dead
  if (m.isDead())
    return;

  // monster hits player
  p.reduceHealth(m.getDPA());
  std::println("The {} hit you for {} damage.", m.getName(), m.getDPA());
}

void fightMonster(Player &p) {
  Monster m{Monster::getRandomMonster()};
  std::println("You have encounterd a {} ({})", m.getName(), m.getSymbol());

  while (!m.isDead() && !p.isDead()) {
    // ask choice
    std::print("(R)un or (F)ight: ");
    char choice{};
    std::cin >> choice;

    switch (choice) {
    case 'F':
    case 'f':
      // hit monster
      attackMonster(p, m);
      // monster hits player
      attackPlayer(m, p);

      break;

    case 'R':
    case 'r':
      // 50% chance of fleeing
      if (Random::get(0, 1) == 1) {
        std::println("You successfully fled.");
        return;
      }
      std::println("You failed to flee.");
      attackPlayer(m, p);
      break;

    default:
      std::println("Invalid Choice");
    }
  }
}

int main() {

  // create Player
  std::cout << "Enter player's name: ";
  std::string name{};
  std::cin >> name;
  Player p{name};
  std::println("Welcome, {}", p.getName());

  // game loop
  while (!p.hasWon() && !p.isDead())
    fightMonster(p);
  // check if player died
  if (p.isDead()) {
    std::println("You died at level {} and with {} gold.", p.getLevel(),
                 p.getGold());
    std::println("Too bad you can't take it with you!");
  } else if (p.hasWon()) {
    std::println("You have won, congrats.");
    std::println("Your level was {} and you had {} gold.", p.getLevel(),
                 p.getGold());
  }

  return 0;
}