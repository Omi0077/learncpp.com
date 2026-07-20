#include <iostream>
#include <limits>
#include <vector>

template <typename T> void printArray(const std::vector<T> &arr) {
  for (T i : arr)
    std::cout << i << ' ';
  std::cout << '\n';
}

template <typename T> int searchInArray(const std::vector<T> &arr, T val) {
  std::size_t left{0};
  std::size_t right{arr.size() - 1};

  while (left <= right) {
    std::size_t middle{left + ((right - left) / 2)};
    if (val == arr[middle])
      return static_cast<int>(middle);
    else if (val < arr[middle])
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;
}

int main() {
  std::vector arr{4, 6, 7, 8, 9};
  int val{};
  while (1) {
    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> val;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (std::cin.peek() != '\n' && !std::cin.eof()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if (val < 1 || val > 9)
      continue;

    break;
  }

  // printArray<int>(arr);
  printArray(arr);

  int index{searchInArray(arr, val)};
  if (index != -1) {
    std::cout << "the number " << val << " has index " << index << '\n';
  } else {
    std::cout << "the number " << val << " was not found" << '\n';
  }

  return 0;
}