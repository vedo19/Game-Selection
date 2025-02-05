#ifndef RockPaperScissors_H
#define RockPaperScissors_H

#include <iostream>

#include "RockPaperScissors.h"
using namespace std;

class RockPaperScissors {
  public:
  char user_input;

  char computer_input;
  const char ROCK = 'r';
  const char PAPER = 'p';
  const char SCISSORS = 's';

  char Comp_Choice();
  char User_Choice();
  void Print_Option(char option);
  bool check_inputs(char user_input, char computer_input);
};

#endif