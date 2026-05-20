#include <iostream>

// static int x = 50;
// to make non const global var internal we use static keyword

// static constexpr int y = 100;
// const and constexpr globals are by default internal , so static isnt needed , if used it will be ignored

static void print()
{
  std::cout << "hello" << std::endl;
}

// functions are by default external , we use static to make it internal