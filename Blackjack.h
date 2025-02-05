#include <iostream>

using namespace std;

#ifndef Blackjack_H
#define Blackjack_H

class Blackjack {
  public:
  int A = 11;
  int J = 10;
  int Q = 10;
  int K = 10;
  int deck[14] = {A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};
  string deckv[14] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  int r = 0;

  int dealerfirstcard = 0;
  string dfc;
  int dealersecondcard = 0;
  string dsc;
  int dealer = 0;

  int playerfirstcard = 0;
  string pfc;
  int playersecondcard = 0;
  string psc;

  int player = 0;
  int playerA = 0;
  int dealerA = 0;
  int dealerAA = 0;

  bool a = 0;
  bool da = 0;

  void dealingCards();
  int imediateGameOver();
  void handsWithA();
  int playing();
};

#endif