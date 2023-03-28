#include <string>
#include "player.hpp"


using namespace std;
namespace ariel{
    class Game {
    public:
        Player p1;
        Player p2;

        Game(Player p1, Player p2);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}
