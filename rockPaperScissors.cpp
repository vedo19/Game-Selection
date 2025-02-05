#include "RockPaperScissors.h"

#include <iostream>
using namespace std;

char RockPaperScissors::Comp_Choice() {
  srand(time(0));

  int num = rand() % 3 + 1;

  if (num == 1)
    return 'r';

  if (num == 2)
    return 'p';

  if (num == 3)
    return 's';
  return 0;
}

char RockPaperScissors::User_Choice() {
  char x;
  cout << "Welcome to Rock, Paper and Scissors Game!" << endl;
  cout << "please choose one of the following options:" << endl;

  cout << "(r) is rock " << endl;
  cout << "(p) for paper " << endl;
  cout << "(s) for scissors " << endl;

  cin >> x;

  while (x != 'r' && x != 'p' && x != 's') {
    cout << "Don't act smart,pick only the one of 3 options. " << endl;

    cout << "(r) is rock " << endl;
    cout << "(p) for paper " << endl;
    cout << "(s) for scissors " << endl;

    cin >> x;
  }

  return x;
}

void RockPaperScissors::Print_Option(char option) {
  if (option == 'r')
    cout << "Rock" << endl;
  if (option == 'p')
    cout << "Paper" << endl;
  if (option == 's')
    cout << "Scissors" << endl;
}

bool RockPaperScissors::check_inputs(char user_input, char computer_input) {
  if (user_input == ROCK && computer_input == PAPER) {
    cout << "Computer is the  WINNER, Paper suffocates Rock" << endl;
    return false;
  }

  else if (user_input == PAPER && computer_input == SCISSORS) {
    cout << "Computer is the  WINNER, Scissors slash Paper." << endl;
    return false;
  }

  else if (user_input == SCISSORS && computer_input == ROCK) {
    cout << "Computer is the  WINNER, Rock smashes Scissors." << endl;
    return false;

  }

  else if (user_input == ROCK && computer_input == SCISSORS) {
    cout << "You are WINNER, Rock smashes Scissors" << endl;
    return true;

  }

  else if (user_input == PAPER && computer_input == ROCK) {
    cout << "You are WINNER, Paper suffocates Rock." << endl;
    return true;
  }

  else if (user_input == SCISSORS && computer_input == PAPER) {
    cout << "You are  WINNER, Scissors slash Paper." << endl;
    return true;
  }

  else {
    cout << "its a TIE" << endl;
    return false;
  }
}
