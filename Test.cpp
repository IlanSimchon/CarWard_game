#include "doctest.h"
#include "iostream"
#include "math.h"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"

using namespace std;
using namespace ariel;


Player p1("Alice");
Player p2("Bob");

TEST_CASE("Tests of numbers") {

    Game TestGame(p1, p2);

    CHECK((p1.cardesTaken(), 0));
    CHECK((p2.cardesTaken(), 0));

    CHECK((p1.stacksize(), 26));
    CHECK((p2.stacksize(), 26));

    TestGame.playTurn();

    CHECK((p1.stacksize() < 26 && p2.stacksize() < 26));
    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 0));

    for (int i = 0; i < 5; ++i) {
        TestGame.playTurn();
        CHECK((p1.stacksize() == p2.stacksize()));
        CHECK((p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52));
    }

    TestGame.playAll();

    CHECK((p1.stacksize() == 0));
    CHECK((p2.stacksize() == 0));
    CHECK((p1.cardesTaken() + p2.cardesTaken() == 52));

}

Player p3("Gabriel");
Player p4("Keren");

TEST_CASE("Tests of exceptions"){


    CHECK_THROWS_AS_MESSAGE(Game samePlayer(p3,p3) , exception , "Player can not fight with himself");

    Game exceptionsTest(p3,p4);

    CHECK_THROWS_AS_MESSAGE(exceptionsTest.printLastTurn() , exception , "The game hasn't started yet");

    exceptionsTest.playTurn();

    CHECK_NOTHROW(exceptionsTest.printLastTurn());

    if(p3.stacksize() != 0) {
        CHECK_THROWS_AS_MESSAGE(exceptionsTest.printWiner(), exception  , "The winner is determined only at the end of the game");
    }
    exceptionsTest.playAll();


    CHECK_THROWS_AS_MESSAGE(exceptionsTest.playTurn() , exception , "The game is over, you will not be able to play any more turns");

    CHECK_THROWS_AS_MESSAGE(exceptionsTest.playAll() , exception , "The game is over, you will not be able to play any more turns");

    CHECK_NOTHROW(exceptionsTest.printLog());
    CHECK_NOTHROW(exceptionsTest.printStats());

    Game winnersGame(p1,p3);

    while (p1.stacksize() > 0){
        CHECK_NOTHROW(winnersGame.playTurn());
    }
    CHECK_THROWS_AS_MESSAGE(exceptionsTest.playTurn() , exception , "The game is over, you will not be able to play any more turns");


}


