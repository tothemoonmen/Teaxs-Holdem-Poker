#include "startup.h"
#include "bot.h"
using namespace std;
int main() {
    // A BUNCH OF TESTS IS BELOW
 //cards mycard;
//    cards card2;
//    mycard.drawCard();
// mycard.print();
//    card2.drawCard();
//    card2.print();
//    mydealer.flop();
////    player1.raise();
//mydealer.showCards();
//mydealer.sort();
//cout<<"After sorting the hand is: "<<endl;
//mydealer.showCards();
//mydealer.showCards();
////mycard.indexCardValue();
//player1.print();
//mydealer.showCards();
//player player1;
//player1.print();
//player1.choice();
//player computer;
//player1.showCards();
//computer.showCards();
//mybot.showCards();

startup::welcome();
    bot mybot;
    mybot.botBetRound1();
//mybot.botBetRound4(); use this to skip to end but need to uncomment draw in botBetRound4



    return 0;
}
