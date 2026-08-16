#include <iostream>
#include <memory>

class Resource
{
public:
  int i{10};
  Resource() { std::cout << "Resource created\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
  auto uptr{std::make_unique<Resource>()};
  // we can create/construct shared_ptr from unique ptr via move
  // with help of converting contructor that accepts rvalue refrence of unique ptr

  // auto sptr {std::shared_ptr<Resource>{std::move(uptr)}};
  // or this
  std::shared_ptr<Resource> sptr{std::move(uptr)}; // non explicit construcor, cant type deduce here

  const auto sptr2{sptr};

  std::cout << ((uptr) ? "still has " : "moved from ") << uptr.get() << "\n";
  std::cout << ((sptr) ? "still has " : "moved from ") << sptr.get() << "\n";
  std::cout << ((sptr2) ? "still has " : "moved from ") << sptr2.get() << "\n";

  sptr2->i = 100; // this is allowed in const

  std::cout << sptr->i << '\n';

  // sptr2 = std::make_shared<Resource>(); // this isnt

  // shared ptr is const not the resource

  return 0;
}