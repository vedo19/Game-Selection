#include <iostream>
// headers
#include <unistd.h>

#include "Blackjack.h"
#include "RockPaperScissors.h"
#include "TicTacToe.h"

using namespace std;

int main() {
  // prompt user to choose if he wants to player a multiplayer game or a singleplayer game
  int game;
  cout << "Press 1 to play a singleplayer game or press 2 to play a multiplayer game: ";
  cin >> game;

  // if user wants to play a singleplayer game
  if (game != 1 && game != 2) {
    cout << "Invalid input" << endl;
    return 0;
  } else if (game == 1) {
    // singleplayer game
    // prompt user to choose if he wants to play rock paper scissors or tic tac toe
    int gameType;
    int coins = 100;
    cout << "Each game costs 10 coins" << endl;
    cout << "Winning a game = +10 coins" << endl;
    cout << "Losing or a tie = -10 coins" << endl;
    if (coins <= 0) {
      cout << "You have no coins left" << endl;
      return 0;
    }
    while (coins > 0) {
      cout << "You have " << coins << " coins" << endl;
      cout << "Press 1 to play rock paper scissors, press 2 to play blackjack ";

      cin >> gameType;

      if (gameType == 1) {
        // rock paper scissors
        RockPaperScissors rps;

        rps.user_input = rps.User_Choice();
        cout << "User input  is: " << endl;
        rps.Print_Option(rps.user_input);

        cout << "Computer's input  is: " << endl;
        rps.computer_input = rps.Comp_Choice();
        rps.Print_Option(rps.computer_input);

        bool isWinner = rps.check_inputs(rps.user_input, rps.computer_input);
        if (isWinner) {
          coins += 10;
        } else {
          coins -= 10;
        }
      } else if (gameType == 2) {
        cout << "Welcome to BLACKJACK" << endl;
        // obj
        Blackjack game;
        srand(time(0));
        game.dealingCards();
        int isWinner = game.imediateGameOver();
        if (isWinner == 1) {
          coins += 10;
          continue;
        } else if (isWinner == 0) {
          coins -= 10;
          continue;
        }
        game.handsWithA();
        isWinner = game.playing();
        if (isWinner == 1) {
          coins += 10;
          continue;
        } else if (isWinner == 0) {
          coins -= 10;
          continue;
        }
      }
    }
  } else if (game == 2) {
    // multiplayer game
    char again;
    cout << "Welcome to Tic Tac Toe Multiplayer Game!" << endl;
    do {
      // tic tac toe
      TicTacToe game;
      game.counter = 0;  // setting to be equal to 0 in the beginning of a game
      game.fieldMake();
      while (1)  // Run forever, until there is no winner of the game or match is draw.
      {
        game.counter++;  // increase every time by one when entering loop as one of the fields become "ocuppied" by 'X' or 'O'
        game.assignValue();
        game.fieldMake();
        if (game.gameWin() == 'X')  // checking if returned value from our funcrion is 'X', if it is...
        {
          cout << "Congradulations X wins!" << endl;  // player 'X' wins
          break;                                      // terminates our infinite while loop
        } else if (game.gameWin() == 'O')             // if our returned value is not 'X', checking if it is 'O'...
        {
          cout << "Congradulations O wins!" << endl;           // player 'O' wins
          break;                                               // terminates our infinite while loop
        } else if (game.gameWin() == '/' && game.counter == 9) /* if no one of if - statements from line 147 - 184 is true '/' is returned
                                                        and if counter is equal to 9, so there are characters in all fields */
        {
          cout << "It's a draw!" << endl;  // result is draw
          break;                           // terminates our infinite while loop
        }
        game.playerChange();
      }
      cout << "Do you want to play again? (y/n): ";
      cin >> again;
    } while (again == 'y' || again == 'Y');
  }

  cout << "Thank you for playing!" << endl;

  return 0;
}
