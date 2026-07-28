#include <iostream>
#include <print>
#include <functional>

bool getNum(int &num, std::string_view title)
{
  while (true)
  {
    std::print("Enter {} number: ", title);
    std::cin >> num;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (!(std::cin.peek() == '\n' || std::cin.eof()))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    return true;
  }
}

bool getOperation(char &c)
{
  while (true)
  {
    std::print("Enter operation: ");
    std::cin >> c;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (!(std::cin.peek() == '\n' || std::cin.eof()))
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (!(c == '+' || c == '-' || c == '*' || c == '/'))
      continue;

    return true;
  }
}

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int multiply(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  return a / b;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char operation)
{
  switch (operation)
  {
  case '+':
    return add;
  case '-':
    return subtract;
  case '*':
    return multiply;
  case '/':
    return divide;
  }
  return nullptr;
}

int main()
{
  int num1{}, num2{};
  char operation{};
  getNum(num1, "first");
  getOperation(operation);
  getNum(num2, "second");

  ArithmeticFunction f{getArithmeticFunction(operation)};
  if (!f)
    return 1;
  int result{f(num1, num2)};

  std::println("result: {}", result);

  return 0;
}