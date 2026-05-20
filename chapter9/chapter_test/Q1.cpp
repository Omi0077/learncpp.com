#include <iostream>
#include <limits>

#include "Random.h"

bool hasUnextractedInput()
{
  return !(std::cin.eof() || std::cin.peek() == '\n');
}

void ignoreLine()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readGuess(int guess_count, int min, int max)
{
  while(1)
  {
    std::cout << "# Guess " << guess_count << " : ";
    int user_input{};
    std::cin >> user_input;
      // ignoreLine();
    
    if(std::cin.fail())
    {
      std::cin.clear();
      ignoreLine();
      std::cout << "invalid input try again!\n";
      continue;
    }
    else if(user_input < min || user_input > max) 
    {
      std::cout << "out of bound guess try again!\n";
      continue;
    }
    else if(hasUnextractedInput())
    {
      std::cin.clear();
      ignoreLine();
      std::cout << "invalid input try again!\n";
      continue;
    }
    return user_input;
  }
}

// char read_choice()
// {

// }

void playHiLo(int tries, int min, int max)
{
  std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

  int random_number{Random::get(min, max)};

  for (int guess_count = 1; guess_count <= tries; ++guess_count)
  {
    // std::cout << "# Guess " << guess_count << " : ";

    int guessed_num{readGuess(guess_count, min, max)};
    // std::cin >> guessed_num;

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

    if(hasUnextractedInput())
    {
      std::cin.clear();
      ignoreLine();
      continue;
    }

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