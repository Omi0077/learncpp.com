#include <iostream>

// 3 levels from worst to best

// class Yogurt{
//   std::string m_flavour{"vanilla"};

//   public:
//   void setFlavour(std::string_view f){ m_flavour = f; }
//   const std::string& getFlavour() const { return m_flavour; }

//   void print(){
//     std::cout << "ther yogurst has flavour " << m_flavour << "\n";
//   }
// };

// // worst access member directly even when getter exists, if class implementation is
// // changed print() also needs to be changed
// // string printed is application specific 

// class Yogurt{
//   std::string m_flavour{"vanilla"};

//   public:
//   void setFlavour(std::string_view f){ m_flavour = f; }
//   const std::string& getFlavour() const { return m_flavour; }

//   void print(std::string_view preFix){
//     std::cout << preFix << ' ' << getFlavour() << "\n";
//   }
// };

// // better but still not great
// // if implementation is changed no need to change , doesnt directly access data members
// // has prefix but still imposes how things are printed

class Yogurt{
  public:
  void setFlavour(std::string_view f){ m_flavour = f; }
  const std::string& getFlavour() const { return m_flavour; }

  // void print(std::string_view preFix){
  //   std::cout << preFix << ' ' << getFlavour() << "\n";
  // }
  private:
    std::string m_flavour{"vanilla"};
};

void print(const Yogurt& yogurt){
  std::cout << "hey my yogust has " << yogurt.getFlavour() << " flavour\n";
}

// best 
// doesnt access member directly(cant)
// no change needed when class implemntation is changed
// each application can provide its own print() function

int main(){
  Yogurt y{};
  y.setFlavour("choclate");
  print(y);
  return 0;
}