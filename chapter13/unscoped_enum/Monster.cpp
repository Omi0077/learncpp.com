#include <iostream>

namespace Monster
{
  enum Monster
  {
    orc,
    goblin,
    troll,
    orge,
    skeleton,
  };
}

int main(){
  [[maybe_unused]]Monster::Monster monster1 {Monster::troll};
  std::cout << monster1 << "\n";
}