#include <iostream>

class PoweredDevice {
public:
  PoweredDevice(int power) { std::cout << "PoweredDevice: " << power << '\n'; }
};

class Printer : virtual public PoweredDevice {
public:
  Printer(int printer, int power)
      : PoweredDevice(
            power) { // this gets ignored only Copier can init PoweredDevice
    std::cout << "Printer: " << printer << '\n';
  }
};

class Scanner : virtual public PoweredDevice {
public:
  Scanner(int scanner, int power)
      : PoweredDevice(
            power) { // this gets ignored only Copier can init PoweredDevice
    std::cout << "Scanner: " << scanner << '\n';
  }
};

class Copier : public Printer, public Scanner {
public:
  Copier(int scanner, int printer, int power)
      : PoweredDevice{power}, Printer{printer, power}, Scanner{scanner, power} {
  }
};

int main() {
  Copier c{1, 2, 3};
  return 0;
}