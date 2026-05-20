#include <iostream>

class Car
{
  std::string model;

  public:
    Car(): model("unkown"){
      std::cout << "constructor called" << std::endl;
    }
    Car(std::string model): model(model) {
      std::cout << "constructor called" << std::endl;
    }
    ~Car()
    {
      std::cout << "destructor called" << std::endl;
    }
    const std::string& get_model()
    {
      return this->model;
    }
};

int main()
{
//   Car A ;
  Car *B = new Car("M5"); // this allocates and call constructor
  Car *C = (Car*)malloc(sizeof(Car)); // this only allocates

  delete(B);
  // delete(C);
  free(C); // same here this frees memory but doesnt call destructor
}