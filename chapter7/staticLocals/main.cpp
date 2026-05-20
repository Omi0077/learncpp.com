#include <iostream>

int generateID()
{
  static int initialID {956235};
  return ++initialID;
}

int main()
{
  std::cout << "generating 10 IDs" << std::endl;

  for(int i=0; i<10; i++)
  {
    std::cout << "ID " << i+1 << " : " << generateID() << std::endl;
  }

  return 0;
}