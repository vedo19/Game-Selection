#ifndef TicTacToe_H
#define TicTacToe_H

#include <iostream>
using namespace std;

class TicTacToe {
  public:
  char matrixTTT[3][3] = {'1', '2', '3', '4', '5',
                          '6', '7', '8', '9'}; /* creating matrix of 3 * 3 that will represent field for our game,
  there are 9 fields and each one is denotaded by a number */

  char player = 'X';  // player in the game
  int counter;        // how many times each move was made or better to see if all fields are filled with the characters

  void fieldMake();     // function that will make field for our game
  void assignValue();   // function that will assign value to the field
  void playerChange();  // function that will change player
  char gameWin();       // function that will check if there is a winner
};

#endif