#include <iostream>

class Entity
{
  private:
    int x = 50, y;
    mutable int z;
  public:
    int get_x() const // so const here is mandatory
    {
      // x = 56; // this cannot be modified inside here
      z = 669; // this method can still modify mutable members
      return x;
    }
};

void printEntity(const Entity& e) // this function promises not to modify Entity object
                                  // but its calling something that could potentially 
{
  std::cout << e.get_x() << std::endl;
}

int main()
{

  Entity e;

  printEntity(e);

  // const int MAX_B_COUNT = 12;

  // const int * a = new int;

  // // *a = 17;
  // a = (int*)&MAX_B_COUNT;
  // a = nullptr;
  // std::cout<< *a << std::endl;
}