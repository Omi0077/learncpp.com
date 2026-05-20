#include <iostream>
#include <random>
#include <chrono>

int main(void)
{
  std::mt19937 mt {
    static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now()
    .time_since_epoch()
    .count())
  };

  // setting range
  std::uniform_int_distribution die6 {1,6};

  for(auto i=0;i<10; i++)
    // std::cout << mt.operator()() << "\n";
    // std::cout << mt() << "\n";
    std::cout << die6(mt) << " ";


  /*
  std::chrono::high_resolution_clock is a popular choice instead of std::chrono::steady_clock. std::chrono::high_resolution_clock is the clock that uses the most granular unit of time, but it may use the system clock for the current time, which can be changed or rolled back by users. std::chrono::steady_clock may have a less granular tick time, but is the only clock with a guarantee that users cannot adjust it.
  */
  return 0;
}