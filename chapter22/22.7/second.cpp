#include <iostream>
#include <memory>

class Person {
  std::string name_{};
  std::weak_ptr<Person> partner_{}; // this is just an observer, not counted
                                    // when looking for co-owners

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

    p1->partner_ = p2;
    p2->partner_ = p1;

    std::cout << p1->name_ << " has now partnered up with " << p2->name_
              << '\n';

    return true;
  }

  const std::string &getName() const { return name_; }
  std::shared_ptr<Person> getPartner() const { return partner_.lock(); }
};

int main() {
  auto aman{std::make_shared<Person>("aman")};
  auto bablu{std::make_shared<Person>("bablu")};

  partnerUp(aman, bablu);

  // "aman is not leting bablu die , bablu is not letting aman die. True love
  // never dies." "didnt age well ! "

  auto partner{aman->getPartner()};

  std::cout << aman->getName() << " is " << partner->getPartner()->getName()
            << '\n';

  std::weak_ptr<Person> sidelover{bablu};
  std::cout << ((sidelover.expired()) ? "he is now aman's\n"
                                      : "I still love him\n");
  return 0;
}