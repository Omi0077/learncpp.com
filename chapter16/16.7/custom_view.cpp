#include <iostream>
#include <vector>

template <typename T> class SignedArrayView {
private:
  const T &m_array{};

public:
  using Index = std::ptrdiff_t;

  explicit SignedArrayView(const T &array) : m_array{array} {}

  constexpr Index size() const { return static_cast<Index>(m_array.size()); }

  constexpr auto &operator[](Index index) {
    return m_array[static_cast<typename T::size_type>(index)];
  }
  constexpr auto &operator[](Index index) const {
    return m_array[static_cast<typename T::size_type>(index)];
  }
};

int main() {
  std::vector v{1, 2, 3, 4, 5, 6};
  SignedArrayView sav{v};

  for (auto i{sav.size() - 1}; i >= 0; i--) {
    std::cout << sav[i] << '\n';
  }

  return 0;
}