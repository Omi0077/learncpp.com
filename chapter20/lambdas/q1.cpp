#include <algorithm>
#include <array>
#include <iostream>

struct Student {
  std::string m_name{};
  int points{};
};

int main() {
  std::array<Student, 8> arr{{{"Albert", 3},
                              {"Ben", 5},
                              {"Christine", 2},
                              {"Dan", 8}, // Dan has the most points (8).
                              {"Enchilada", 4},
                              {"Francis", 1},
                              {"Greg", 3},
                              {"Hagrid", 5}}};

  auto comparator{[](const Student &a, const Student &b) -> bool {
    return a.points < b.points;
  }};

  auto studentWithHighestGrade{
      std::max_element(arr.begin(), arr.end(), comparator)};

  std::cout << studentWithHighestGrade->m_name << " is the best student\n";

  return 0;
}
