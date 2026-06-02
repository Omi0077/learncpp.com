#include <iostream>
// #include <cstdint>

enum TransactionStatus : u_int8_t { // explicitly given base type
  unknown, //default
  complete,
  pending,
  failed,
};

int main(void){
  TransactionStatus status {}; // zero init. initializes to 0 even if it doesnt exist
  std::cout << status << "\n";

  // status = 1; // no implicit conversion from int to enum
  status = static_cast<TransactionStatus>(1); // so either use stattic_cast
  std::cout << status << "\n";

  // or
  // when base type is explicitly defined we can list initialize enum with integral value

  // status = 1;
  // status{1} // not initialization

  // TransactionStatus status1 {1032}; // out of range
  TransactionStatus status1 {10};
  std::cout << status1 << "\n";
  std::cout << sizeof(status1) << "\n";
  
  // snce base type is int8_t it is treated as char so values arent printing on terminal
  return 0;
}