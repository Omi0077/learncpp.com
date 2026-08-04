#include <functional>
#include <iostream>

void myCall(const std::function<void()> &fn) { fn(); }

int main() {

  int i{0};

  auto lambdaObject{[i]() mutable { std::cout << ++i << '\n'; }};

  // std::function lambdaObject{[i]() mutable { std::cout << ++i << '\n'; }};

  myCall(std::ref(lambdaObject));
  myCall(std::ref(lambdaObject));
  myCall(std::ref(lambdaObject));

  return 0;
}
