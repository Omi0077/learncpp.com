#include <iostream>

#include "Random.h"

void playHiLo(int tries, int min, int max)
{
  std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

  int random_number{Random::get(min, max)};

  for (int guess_count = 1; guess_count <= tries; ++guess_count)
  {
    std::cout << "# Guess " << guess_count << " : ";

    int guessed_num{};
    std::cin >> guessed_num;

    if (guessed_num == random_number)
    {
      std::cout << "Correct! You Win!\n";
      return;
    }
    else if (guessed_num > random_number)
    {
      std::cout << "Too High\n";
    }
    else if (guessed_num < random_number)
    {
      std::cout << "Too Low\n";
    }
  }

  std::cout << "Sorry, you lose. The correct number was " << random_number << ".\n";
  return;
}

bool playAgain()
{
  while (1)
  {
    std::cout << "Would you like to play again (y/n)? ";
    char choice{};
    std::cin >> choice;

    switch (choice)
    {
    case 'y':
    case 'Y':
      return true;
    
    case 'n':
    case 'N':
      return false;
    }
  }
}

int main()
{

 constexpr int tries {7};
 constexpr int min {1};
 constexpr int max {100};

 do
 {
  playHiLo(tries, min, max);
 } while (playAgain());
 
}