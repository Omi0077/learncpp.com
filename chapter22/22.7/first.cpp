#include <iostream>
#include <memory>

class Person {
  std::string name_{};
  std::shared_ptr<Person> partner{};

public:
  Person(std::string_view name) : name_{name} {
    std::cout << name_ << " CREATED\n";
  }
  ~Person() { std::cout << name_ << " DESTROYED\n"; }

  friend bool partnerUp(std::shared_ptr<Person> &p1,
                        std::shared_ptr<Person> &p2) {
    if (!p1 || !p2) {
      return false;
    }

    p1->partner = p2;
    p2->partner = p1;

    std::cout << p1->name_ << " has now partnered up with " << p2->name_ << '\n';

    return true;
  }
};

int main() { 
  auto aman {std::make_shared<Person>("aman")};
  auto bablu {std::make_shared<Person>("bablu")};

  partnerUp(aman, bablu);

  // "aman is not leting bablu die , bablu is not letting aman die. True love never dies."
  return 0;
 }