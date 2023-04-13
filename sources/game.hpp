#include <string>
#include "player.hpp"
#include <algorithm>
#include <random>
#include <deque>


using namespace std;

namespace ariel{
    class Game {
    public:
        Player &player1;
        Player &player2;
        deque<string> log;
        int draw_turn;

        Game(Player &player1, Player &p2);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}
