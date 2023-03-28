#ifndef Player_HPP
#define Player_HPP
#include <string>
using namespace std;

namespace ariel {
    class Player {
    public:
        string name;

        Player(string name);

        int stacksize();

        int cardesTaken();

    };
}
#endif
