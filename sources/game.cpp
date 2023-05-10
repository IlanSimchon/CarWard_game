#ifndef GAME_HPP
#define GAME_HPP
#include "game.hpp"
#include <iostream>
#include <vector>

using namespace ariel;
using namespace std;

Game::Game(Player &player1, Player &player2) : player1(player1) , player2(player2) {
    this->draw_turn = 0;

    vector<Card> arr;
    for (int i = 1; i < 14; ++i) {
        arr.push_back(Card(i , "hearts"));
        arr.push_back(Card(i , "diamonds"));
        arr.push_back(Card(i , "clubs"));
        arr.push_back(Card(i , "spades"));
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);

    for (int i = 0; i < 26 ; ++i) {
        this->player1.stack.push_back(arr.back());
        arr.pop_back();
        this->player2.stack.push_back(arr.back());
        arr.pop_back();
    }


}

void Game::playTurn() {
    if (&this->player1 == &this->player2)
        throw invalid_argument("A player cannot play against himself");
    if (player1.stacksize() == 0 || player2.stacksize() == 0)
        throw exception();
    Card c1 = this->player1.stack.back();
    this->player1.stack.pop_back();
    Card c2 = this->player2.stack.back();
    this->player2.stack.pop_back();
    int cards = 2;
    string turn = player1.name + " played " + c1.data() + " " + player2.name + " played " + c2.data() + ". ";

    while (c1 == c2) {
        draw_turn++;
        turn += "Draw. ";

        if (player1.stacksize() == 1 || player2.stacksize() == 1) {
            turn += "The stack is over";
            this->player1.stack.pop_back();
            this->player2.stack.pop_back();
            cards += 2;

            this->player1.taken += cards / 2;
            this->player2.taken += cards / 2;

            log.push_back(turn);
            return;
        } else if (player1.stacksize() == 0 || player2.stacksize() == 0) {
            turn += "The stack is over";

            this->player1.taken += cards / 2;
            this->player2.taken += cards / 2;

            log.push_back(turn);
            return;
        } else {
            this->player1.stack.pop_back();
            this->player2.stack.pop_back();

            c1 = this->player1.stack.back();
            this->player1.stack.pop_back();
            c2 = this->player2.stack.back();
            this->player2.stack.pop_back();

            cards += 4;
            turn += player1.name + " played " + c1.data() + " " + player2.name + " played " + c2.data() + ". ";
        }
    }
        if (c1 < c2) {
            this->player2.taken += cards;
            this->player2.won_round++;
            turn += player2.name + " wins.";
        } else {
            this->player1.taken += cards;
            this->player1.won_round++;
            turn += player1.name + " wins.";

        }
        log.push_back(turn);
}

    void Game::printLastTurn() {
        if(this->log.size() == 0)
            cout << "The Game not started yet" << endl;
        else
            cout << this->log.back() << endl;
    }

    void Game::playAll() {
        if (player1.stacksize() > 0 && player2.stacksize() > 0) {
            while (player1.stack.size() > 0 && player2.stack.size() > 0)
                playTurn();
        }
    }

    void Game::printWiner() {
        if(player1.stacksize() > 0){
            cout << "The game not over yet" << endl;
        }
        else {
            if (this->player1.taken > this->player2.taken)
                cout << player1.name << endl;
            else if (this->player1.taken < this->player2.taken)
                cout << player2.name << endl;
            else {
                cout << "Draw" << endl;
            }
        }
    }

    void Game::printLog() {
        if(this->log.size() == 0)
            cout << "The Game not started yet" << endl;
        else {
            for (string s: this->log) {
                cout << s << endl;
            }
        }
    }

    void Game::printStats() {
        if(player1.stacksize() > 0){
            cout << "The game not over yet" << endl;
        }
        else {
            double numOfTurns = static_cast<double>(this->log.size());
            double winP1 = this->player1.won_round / numOfTurns * 100;
            double winP2 = this->player2.won_round / numOfTurns * 100;

            cout << "The game over after " << numOfTurns << " rounds" << endl;
            cout << this->player1.name << " won " << winP1 << "% of the rounds and took " << this->player1.taken << " cards."
                 << endl;
            cout << this->player2.name << " won " << winP2 << "% of the rounds and took " << this->player2.taken << " cards."
                 << endl;
            cout << "there was a " << this->draw_turn << " draws" << endl;

        }
    }



#endif