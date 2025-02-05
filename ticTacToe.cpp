#include "TicTacToe.h"

#include <iostream>
using namespace std;

void TicTacToe::fieldMake() {
  system("cls");  // clear the console window

  for (int i = 0; i < 3; i++)  // rows
  {
    cout << "------" << endl;
    for (int j = 0; j < 3; j++)  // columns
    {
      cout << matrixTTT[i][j] << "|";
    }
    cout << endl;
  } /* loop is made in this way: entering first for loop(row) and then entering second one(column) each time.
    Repeat this 3 times. Each time row will be assign as this "1 2 3" and by entering first for loop three times
    and second one nine times we get: 1 2 3
                                      4 5 6
                                      7 8 9
    Values are get from the matrixTTT and "------" and "|" are boundaries to make it visual better*/
}

void TicTacToe::assignValue() {
  int nField;
  cout << "It's " << player << " turn. "
       << "Please press the number of the field: ";  // showing which player has a turn
  cin >> nField;

  if (nField == 1) {
    if (matrixTTT[0][0] == '1')
      matrixTTT[0][0] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 2) {
    if (matrixTTT[0][1] == '2')
      matrixTTT[0][1] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 3) {
    if (matrixTTT[0][2] == '3')
      matrixTTT[0][2] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 4) {
    if (matrixTTT[1][0] == '4')
      matrixTTT[1][0] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 5) {
    if (matrixTTT[1][1] == '5')
      matrixTTT[1][1] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 6) {
    if (matrixTTT[1][2] == '6')
      matrixTTT[1][2] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 7) {
    if (matrixTTT[2][0] == '7')
      matrixTTT[2][0] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 8) {
    if (matrixTTT[2][1] == '8')
      matrixTTT[2][1] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  } else if (nField == 9) {
    if (matrixTTT[2][2] == '9')
      matrixTTT[2][2] = player;
    else {
      cout << "Field is already in use try again!" << endl;
      assignValue();
    }
  }

} /* These if/else if statements suggest us where in the field/matrxix our player will have it's position.
     It is important to know that matrix starts from [0][0] and this is example first row in the first column for which '1' will take place.
     For instance if we want to plug it in second row, third column we need to think in head...
     ... ok our matrix start from 0, so second row is certainly one; it is same for colums so our column is two and matrix is [1][2]
     Else statement is telling that our "player" is already inside that particular field, it cannot be used as there is value insdie it. */

void TicTacToe::playerChange() {
  if (player == 'X')
    player = 'O';
  else
    player = 'X';
} /* By every next move(every click) there is changing in player. Our global variable player holds two characters 'X' and 'O'.
  This means that if our player is 'X' it will assign 'O' and if not it will be 'X'. */

char TicTacToe::gameWin() {
  // first player
  if (matrixTTT[0][0] == 'X' && matrixTTT[0][1] == 'X' && matrixTTT[0][2] == 'X')  // row
    return 'X';
  if (matrixTTT[1][0] == 'X' && matrixTTT[1][1] == 'X' && matrixTTT[1][2] == 'X')  // row
    return 'X';
  if (matrixTTT[2][0] == 'X' && matrixTTT[2][1] == 'X' && matrixTTT[2][2] == 'X')  // row
    return 'X';

  if (matrixTTT[0][0] == 'X' && matrixTTT[1][0] == 'X' && matrixTTT[2][0] == 'X')  // column
    return 'X';
  if (matrixTTT[0][1] == 'X' && matrixTTT[1][1] == 'X' && matrixTTT[2][1] == 'X')  // column
    return 'X';
  if (matrixTTT[0][2] == 'X' && matrixTTT[1][2] == 'X' && matrixTTT[2][2] == 'X')  // column
    return 'X';

  if (matrixTTT[0][0] == 'X' && matrixTTT[1][1] == 'X' && matrixTTT[2][2] == 'X')  // diagonal
    return 'X';
  if (matrixTTT[2][0] == 'X' && matrixTTT[1][1] == 'X' && matrixTTT[0][2] == 'X')  // diagonal
    return 'X';

  // second player
  if (matrixTTT[0][0] == 'O' && matrixTTT[0][1] == 'O' && matrixTTT[0][2] == 'O')  // row
    return 'O';
  if (matrixTTT[1][0] == 'O' && matrixTTT[1][1] == 'O' && matrixTTT[1][2] == 'O')  // row
    return 'O';
  if (matrixTTT[2][0] == 'O' && matrixTTT[2][1] == 'O' && matrixTTT[2][2] == 'O')  // row
    return 'O';

  if (matrixTTT[0][0] == 'O' && matrixTTT[1][0] == 'O' && matrixTTT[2][0] == 'O')  // column
    return 'O';
  if (matrixTTT[0][1] == 'O' && matrixTTT[1][1] == 'O' && matrixTTT[2][1] == 'O')  // column
    return 'O';
  if (matrixTTT[0][2] == 'O' && matrixTTT[1][2] == 'O' && matrixTTT[2][2] == 'O')  // column
    return 'O';

  if (matrixTTT[0][0] == 'O' && matrixTTT[1][1] == 'O' && matrixTTT[2][2] == 'O')  // diagonal
    return 'O';
  if (matrixTTT[2][0] == 'O' && matrixTTT[1][1] == 'O' && matrixTTT[0][2] == 'O')  // diagonal
    return 'O';

  return '/';
} /* These if statements are showing on which way player can win the game. We need to check for both player.
     As we can see there are eight if statements for each player because there are eight ways on how to win the game.
     You can win it by either completing one of three rows, on of three colums or one of two diagonals.
     Lines "return 'X'" or "return 'O'" mean that value is return to 'X' or 'O' other lines show what does it actually mean.
     If no of this if statements is correct by default program will return '/'. */
