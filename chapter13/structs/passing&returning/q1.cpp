#include <iostream>

struct AdData{
  int numOfAdWatched{};
  double percentClicked{};
  double averageEarningPerClicked{};
};

void printAdData(const AdData& d){
  std::cout << "No. of Ads watched: " << d.numOfAdWatched << "\n";
  std::cout << "Percent of users clicked on Ad: " << d.percentClicked << "\n";
  std::cout << "Average earning per Ad clicked: " << d.averageEarningPerClicked << "\n";

  std::cout << "Total income: " << d.numOfAdWatched*d.percentClicked*d.averageEarningPerClicked << "\n";
}

int main(){

  AdData d1{};

  std::cout << "Enter no. of Ads watched: ";
  std::cin  >> d1.numOfAdWatched;
  std::cout << "Enter percent of users clicked on Ad: ";
  std::cin  >> d1.percentClicked;
  std::cout << "Enter average earning per Ad clicked: ";
  std::cin  >> d1.averageEarningPerClicked;

  printAdData(d1);
  
  return 0;
}