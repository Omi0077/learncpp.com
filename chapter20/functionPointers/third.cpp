#include <iostream>

bool ascending(int a, int b)
{
  if (a > b)
    return true; // swap needed

  return false;
}

bool descending(int a, int b)
{
  if (a < b)
    return true; // swap needed

  return false;
}

using validateFunc = bool (*)(int, int);

// void bubbleSort(int *arr, int length, validateFunc func)
void bubbleSort(int *arr, int length, bool func(int, int)) // this only works in function parameters
{
  if (!arr || !func)
    return;

  bool swapped{false};
  for (int i{}; i < length - 1; i++)
  {
    swapped = false;
    for (int j{0}; j < length - i - 1; j++)
    {
      if (func(arr[j], arr[j + 1]))
      {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

int main()
{
  int arr[]{1, 6, 2, 3, 8, 3, 9};

  bubbleSort(arr, 7, ascending);
  bubbleSort(arr, 7, descending);

  for (auto i : arr)
  {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}