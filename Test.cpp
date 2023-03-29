#include "doctest.h"
#include "iostream"
#include "math.h"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"

using namespace std;
using namespace ariel;


Player p1("player 1");
Player p2("player 2");

TEST_CASE("Tests of numbers") {

    Game FirstGame(p1, p2);

    CHECK((p1.cardesTaken(), 0));
    CHECK((p2.cardesTaken(), 0));

    CHECK((p1.stacksize(), 26));
    CHECK((p2.stacksize(), 26));

    FirstGame.playTurn();

    CHECK((p1.stacksize() < 26 && p2.stacksize() < 26));
    CHECK((p1.cardesTaken() == 0 || p1.cardesTaken() == 0));

    for (int i = 0; i < 5; ++i) {
        FirstGame.playTurn();
        CHECK((p1.stacksize() == p2.stacksize()));
        CHECK((p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52));
    }

    FirstGame.playAll();

    CHECK((p1.stacksize() == 0));
    CHECK((p2.stacksize() == 0));
    CHECK((p1.cardesTaken() + p2.cardesTaken() == 52));

}

Player p3("player 3");
Player p4("player 4");

TEST_CASE("Tests of exceptions"){

    Game SecondGame(p3,p4);

    CHECK_THROWS_AS_MESSAGE(SecondGame.printLastTurn() , exception , "The game hasn't started yet");

    SecondGame.playTurn();

    CHECK_NOTHROW(SecondGame.printLastTurn());

    if(p3.stacksize() != 0) { // Checking that the game doesn't end in one round
        CHECK_THROWS_AS_MESSAGE(SecondGame.printWiner(), exception  , "The winner is determined only at the end of the game");
    }
    SecondGame.playAll();

    CHECK_THROWS_AS_MESSAGE(SecondGame.playTurn() , exception , "The game is over, you will not be able to play any more turns");

    CHECK_THROWS_AS_MESSAGE(SecondGame.playAll() , exception , "The game is over, you will not be able to play any more turns");

    CHECK_NOTHROW(SecondGame.printLog());
    CHECK_NOTHROW(SecondGame.printStats());


    Player p5("player 5");
    Player p6("player 6");

    Game ThirdGame(p5,p6);

    while (p1.stacksize() > 0){
        CHECK_NOTHROW(ThirdGame.playTurn());
    }
    CHECK_THROWS_AS_MESSAGE(ThirdGame.playTurn() , exception , "The game is over, you will not be able to play any more turns");

}

Player p7("player 7");
Player p8("player 8");
Player p9("player 9");


TEST_CASE("exceptions in accessing players"){


    CHECK_THROWS_AS_MESSAGE(p7.stacksize() , exception , "You need to join the game before retrieving game data");
    CHECK_THROWS_AS_MESSAGE(p7.cardesTaken() , exception , "You need to join the game before retrieving game data");

    CHECK_THROWS_AS_MESSAGE(Game samePlayer(p8,p8) , exception , "Player can not fight with himself");

    Game lastGame(p7,p8);

    CHECK_THROWS_AS_MESSAGE(Game game(p7, p9) , invalid_argument , "One of the players is already playing another game");
}


