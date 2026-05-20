#include <iostream>

class Car
{
  std::string model;
  int gears;

  public:
    Car(): model("unkown"), gears(-1){}
    Car(const std::string& model): model(model), gears(-1) {}
    explicit Car(int gears): gears(gears){}
};

int main()
{
  Car A = Car(7); // this works without explicit
  // std::string model = "m5";
  // Car B = model;

  // Car B = "m5";

}