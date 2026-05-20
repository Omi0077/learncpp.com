#include <iostream>

class Example
{
  public:
    Example()
    {
      std::cout<< "created entity" << std::endl;
    }
    Example(int x)
    {
      std::cout<< "created with: " << x << std::endl;
    }
};

class Entity
{
  private:
    Example ex;  // once here
  public:
    Entity()
      :ex(10)  // this acts as if it was being init at declaration time, thus only 1 example object created
    {
      // and again here 
      // ex = Example(10); // this leads to two times creation of Example object
    }
};

int main()
{
  Entity e;
}