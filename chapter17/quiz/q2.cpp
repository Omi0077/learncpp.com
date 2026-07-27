#include <iostream>
#include <array>
#include <print>
#include <string>
#include <string_view>
#include <vector>

#include "../../important/Random.h"

namespace Potion
{
  enum Type
  {
    healing,
    mana,
    speed,
    invisiblity,
    maxSize,
  };

  constexpr std::array types{healing, mana, speed, invisiblity};

  constexpr std::array<int, maxSize> costs{20, 30, 12, 50};

  using namespace std::string_view_literals; // not needed as type is explicitly provided
  std::array<std::string_view, maxSize> names{"healing"sv, "mana"sv, "speed"sv, "invisiblity"sv};

}

void shop()
{
  std::cout << "Here is our selection for today:\n";
  for (auto p : Potion::types)
  {
    std::println("{}) {} costs {}", static_cast<int>(p), Potion::names[p], Potion::costs[p]);
  }
}

class Player
{
private:
  static constexpr int maxInitGold{100};
  static constexpr int minInitGold{50};

  std::string m_name{};
  std::array<int, Potion::maxSize> m_inventory{};
  int m_gold{};

public:
  explicit Player(std::string_view name) : m_name{name}, m_gold{Random::get(minInitGold, maxInitGold)} {}

  int gold() const { return m_gold; }
  int inventory(Potion::Type p) const { return m_inventory[static_cast<std::size_t>(p)]; }

  void purchase(Potion::Type p)
  {
    m_inventory[p] += 1;
    m_gold -= Potion::costs[p];
  }

  void printInventory() const
  {
    std::println("{}'s inventory:- ", m_name);
    for (std::size_t i{}; i < Potion::maxSize; i++)
    {
      if(m_inventory[i] == 0) continue;

      std::println("{} potion : {}", Potion::names[i], m_inventory[i]);
    }
  }
};

int main()
{
  std::println("Welcome to Roscoe's potion emporium!");
  std::string name{};
  std::cout << "Enter your name: ";
  std::getline(std::cin >> std::ws, name);
  Player p{name};
  std::println("Hello, {}, you have {} gold\n", name, p.gold());

  char choice{};
  while(1){
    shop();
    std::print("\nEnter your choice(0-3): ");
    std::cin >> choice;

    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if(!(std::cin.peek() == '\n' || std::cin.eof())){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if(choice == 'q') return 0;
    if(choice >= '0' && choice <= '3') break;
  }


  p.purchase(static_cast<Potion::Type>(choice-'0'));
  // std::println("{}",p.gold());

  std::println("\nThanks for shopping at Roscoe's potion emporium!\n");
  p.printInventory();
  return 0;
}