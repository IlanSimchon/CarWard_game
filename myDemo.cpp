#include <iostream>
#include <fstream>
#include <sstream>

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
using namespace std;
int main() {


    // Game functions

    Player p1("player1");
    Player p2("player2");

    Game myGame(p1, p2);

    for (int i = 0; i < 3; ++i) {
        myGame.playTurn()  ;
        myGame.printLastTurn();
    }

    myGame.printLog();

    myGame.playAll();

    myGame.printWiner();
    myGame.printLog();
    myGame.printStats();



    // players functions

    Player p3("player3");
    Player p4("player4");

    Game playersGame(p3, p4);

    cout << p3.stacksize() << " " << p4.stacksize() << endl; // should print "26 26"
    cout << p3.cardesTaken() << " " << p4.cardesTaken() << endl; // should print "0 0"

    for (int i = 0; i < 4; ++i) {
        playersGame.playTurn();
        cout << p3.stacksize() + p3.cardesTaken() + p4.stacksize() + p4.cardesTaken() << endl; // should print always 52
    }

    playersGame.playAll();

    cout << p3.stacksize() << " " << p4.stacksize() << endl; // should print "0 0"
    cout << p3.cardesTaken() + p4.cardesTaken() << endl; // should print 52




    // cards functions

    Card c1(10 , "diamonds");
    Card c2(6 , "hearts");
    Card c3(2 , "spades");
    Card c4(1 , "clubs");

    cout << (c2 < c1) << endl; // should print 1
    cout << (c3 < c4) << endl; // should print 0
    cout << (c2 < c4) << endl; // should print 1

    cout << (c2 == Card(6 , "clubs")) << endl; // should print 1
    cout << (c1 == c4) << endl; // // should print 0


    cout << c3.data() << endl; // should print "2 of spades"
    cout << c1.data() << endl; // should print "10 of diamonds"


}