#ifndef Card_HPP
#define Card_HPP

#include <string>
using namespace std;

namespace ariel {
    class Card{
    public:
        int number;
        string type;

        Card(int number , string type);
        int getNumber();
        bool operator==(Card other);
        bool operator<(Card other);
        string data();
    };
}


#endif