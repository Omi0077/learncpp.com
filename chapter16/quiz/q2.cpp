#include <iostream>
#include <vector>
#include <assert.h>

namespace Items
{
  enum Types
  {
    health_potion,
    torch,
    arrow,
    maxCount,
  };

  std::string_view getTypeName(Types t, int amt)
  {
    switch (t)
    {
    case health_potion:
      return (amt <= 1) ? "health potion" : "health potions";
    case torch:
      return (amt <= 1) ? "torch" : "torches";
    case arrow:
      return (amt <= 1) ? "arrow" : "arrows";
    default:
      return "???";
    }
  }
}

int countTotalItems(const std::vector<int> &inventory)
{
  int totalItems{};
  for (int i : inventory) // uses iterators so cant be used in compile time context
  {
    totalItems += i;
  }
  return totalItems;
}

void displayItems(const std::vector<int> &inventory)
{
  for (std::size_t i{0}; i < inventory.size(); i++)
  {
    std::cout << "you have " << inventory[i] << ' ' << Items::getTypeName(static_cast<Items::Types>(i), inventory[i]) << '\n';
  }
}

class Player
{
  std::vector<int> m_inventory{std::vector{1, 5, 10}};

public:
  Player() = default;
  Player(const std::vector<int> &inventory) : m_inventory{inventory}
  {
    assert(m_inventory.size() == Items::maxCount && "Player can have exactly 3 different items\n");
  }
};

int main()
{
  std::vector inventory{2, 1, 1};
  assert(inventory.size() == Items::maxCount && "Player can have exactly 3 different items\n");

  int totalItems{countTotalItems(inventory)};
  displayItems(inventory);
  std::cout << "You have " << totalItems << " total itmes\n";

  return 0;
}