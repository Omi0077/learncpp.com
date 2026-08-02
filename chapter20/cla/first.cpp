#include <iostream>
#include <print>

int main(int argc, char *argv[])
{
  if(argc > 1){
    for(int i{}; i<argc; i++){
      std::println("{} {}", i, argv[i]);
    }
  }
  return 0;
}

/*
1. strings passed in double quotes are considered to be part of the same string
2. Most operating systems will allow you to include a literal double quote by backslashing the double quote
*/