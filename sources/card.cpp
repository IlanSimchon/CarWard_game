#include "card.hpp"

using namespace ariel;


Card::Card(int number , string type) {
    this->number = number;
    this->type = type;
}
int Card::getNumber() {
    return this->number;
}
bool Card::operator==(Card other) {
        return this->number == other.number;
    }

bool Card::operator<(Card other){
    if(this->number == 1 && other.number > 2) return false;
    if(other.number == 1 && this->number > 2) return true;
    return this->number < other.number;
}
string Card::data(){
    string s;
    if(this->number == 13 )
        s += "King ";
    else if(this->number == 12 )
        s += "Queen ";
    else if(this->number == 11 )
        s += "Prince ";
    else
        s+= to_string(this->number) + " ";

    s += "of " + this->type;
    return s;
}


