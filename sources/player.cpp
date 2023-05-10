#include "player.hpp"

using namespace ariel;
Player::Player(string name){
        this->name = name;
        this->taken = 0;
        this->won_round = 0;
    }

int Player::stacksize(){
    return this->stack.size();
}

int Player::cardesTaken(){
    return this->taken;
}
