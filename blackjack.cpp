#include "Blackjack.h"

#include <unistd.h>

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

void Blackjack::dealingCards() {
  // dealing cards to dealer

  r = rand() % 13;
  dealerfirstcard = deck[r];
  dfc = deckv[r];
  r = rand() % 13;
  dealersecondcard = deck[r];
  dsc = deckv[r];
  dealer = dealerfirstcard + dealersecondcard;

  // dealing cards to player

  r = rand() % 13;
  playerfirstcard = deck[r];
  pfc = deckv[r];
  r = rand() % 13;
  playersecondcard = deck[r];
  psc = deckv[r];
  player = playerfirstcard + playersecondcard;
}
int Blackjack::imediateGameOver() {
  // imediate loss/win
  if (player == 21) {
    cout << "Dealer has: ";
    cout << "?";
    cout << " and ";
    cout << dsc;
    cout << " which combined is " << dealer << endl;
    sleep(1);
    cout << "You have: ";
    cout << pfc;
    cout << " and ";
    cout << psc << " which combined is: " << player << " and you have BLACKJACK!";
    sleep(1);
    cout << "You won";
    return 1;
  }
  if (player > 21 && (playerfirstcard != 11 && playersecondcard != 11)) {
    cout << "You have: ";
    cout << pfc << " and ";
    cout << psc << " which combined is: " << player << endl;
    sleep(1);
    cout << "You lost";
    return 0;
  }
  if (dealer == 21) {
    cout << "Dealer has: ";
    cout << dfc;
    cout << " and ";
    cout << dsc;
    cout << " which combined is " << dealer << endl;
    /*cout<<"You have: ";
    sleep(1);
    cout<<pfc;
    sleep(1);
    cout<<" and ";
    sleep(1);
    cout<<psc;
    sleep(1);
    cout<<" which combined is: "<<player<<endl;*/
    sleep(1);
    cout << "You lost";
    return 0;
  }
  return 2;
}
void Blackjack::handsWithA() {
  // calculating hands with A
  player = playerfirstcard + playersecondcard;
  int q;
  bool a = 0;
  if (playersecondcard == 11)
    if (player > 21 && playerfirstcard == 11) {
      playerfirstcard = 1;
      player = playerfirstcard + playersecondcard;
      a = 1;
    }
  if (player < 21 && playerfirstcard == 11) {
    playerA = 1 + playersecondcard;
    a = 1;
  }
  if (player > 21 && playersecondcard == 11) {
    q = playerfirstcard;
    playerfirstcard = playersecondcard;
    playersecondcard = q;
    playersecondcard = 1;
    player = playerfirstcard + playersecondcard;
    a = 1;
  }
  if (player < 21 && playersecondcard == 11) {
    q = playerfirstcard;
    playerfirstcard = playersecondcard;
    playersecondcard = q;
    playerA = 1 + playersecondcard;
    a = 1;
  }
  // calculating dealer's hands with A
  dealer = dealerfirstcard + dealersecondcard;
  int dq;
  bool da = 0;
  if (dealersecondcard == 11)
    if (dealer > 21 && dealerfirstcard == 11) {
      dealerfirstcard = 1;
      dealer = dealerfirstcard + dealersecondcard;
      da = 1;
    }
  if (dealer < 21 && dealerfirstcard == 11) {
    dealerA = 1 + dealersecondcard;
    da = 1;
  }
  if (dealer > 21 && dealersecondcard == 11) {
    dq = dealerfirstcard;
    dealerfirstcard = dealersecondcard;
    dealersecondcard = dq;
    dealersecondcard = 1;
    dealer = dealerfirstcard + dealersecondcard;
    da = 1;
  }
  if (dealer < 21 && dealersecondcard == 11) {
    q = dealerfirstcard;
    dealerfirstcard = dealersecondcard;
    dealersecondcard = q;
    dealerA = 1 + dealersecondcard;
    da = 1;
  }
}
int Blackjack::playing() {
  // showing cards
  cout << "Dealer has: ";
  cout << "?";
  cout << " and ";
  cout << dsc << endl;
  sleep(1);
  cout << "You have: ";
  cout << pfc;
  cout << " and ";
  cout << psc;
  cout << " which combined is " << player;

  if (playerfirstcard == 11) {
    cout << "/" << playerA;
  }
  // Hit me?
  cout << endl;
  string hit;
  int addedcard;
  string addc;
  cout << "Hit me?(Y or N)";
  sleep(1);
  cin >> hit;
  while (hit == "Y" || hit == "y") {
    r = rand() % 13;
    addedcard = deck[r];
    addc = deckv[r];
    player = player + addedcard;
    playerA = playerA + addedcard;
    cout << "You got: ";
    cout << addc;
    cout << " and now your hand is: ";
    if (player > 21) {
      if (a == 1) {
        player = playerA;
        cout << player;
        if (player > 21) {
          cout << endl;
          sleep(1);
          cout << "You lost" << endl;
          return 0;
        }
      }
      if (a == 0) {
        cout << player << endl;
        sleep(1);
        cout << "You lost" << endl;
        return 0;
      }
    }
    if (player < 21) {
      if (a == 1) {
        cout << player << "/" << playerA;
      }
      if (a == 0) {
        cout << player;
      }
    }
    if (player == 21) {
      cout << "21 and you have the BLACKJACK!" << endl;
      cout << "You won" << endl;
      return 1;
    }
    cout << endl;
    cout << "Hit me?";
    cin >> hit;
  }
  // dealer's turn
  int dealeraddedcard;
  string dac;
  bool dealerhit = 0;
  cout << "Dealer has: ";
  cout << dfc;
  cout << " and ";
  cout << dsc;
  cout << " which combined is " << dealer << endl;
  sleep(1);
  if (dealer < 17 && dealer < player) {
    dealerhit = 1;
  }
  while (dealerhit == 1) {
    r = rand() % 13;
    dealeraddedcard = deck[r];
    dac = deckv[r];
    dealerAA = dealer + 1;
    dealer = dealer + dealeraddedcard;
    cout << "Dealer got: ";
    cout << dac;
    cout << " and now has: ";
    if (dealer > 21) {
      if (da == 1) {
        dealer = dealerA;
        cout << dealer << endl;
        if (dealer > 21) {
          sleep(1);
          cout << "You won" << endl;
          return 1;
        }
        if (dac == "A") {
          dealer = dealerAA;
        }
      }
      if (da == 0) {
        cout << dealer << endl;
        sleep(1);
        cout << "You won" << endl;
        return 1;
      }
    }
    if (dealer < 21) {
      if (a == 1) {
        cout << dealer << "/" << dealerA << endl;
      }
      if (a == 0) {
        cout << dealer << endl;
      }
    }
    if (dealer > 16 || dealer > player || dealer == player) {
      dealerhit = 0;
    }
    if (dealer == 21) {
      cout << "21 and has the BLACKJACK :(";
      cout << "You lost" << endl;
      return 0;
    }
  }
  if (dealer == player) {
    cout << "It's a draw" << endl;
    return 0;
  }
  if (dealer > 21) {
    cout << "You won" << endl;
    return 1;
  }
  if (dealer > player) {
    cout << "You lost" << endl;
    return 0;
  }
  if (dealer < player) {
    cout << "You won" << endl;
    return 1;
  }
  return 0;
}
