// Player.h - class declaration for a player

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>

class Player {
    std::string name;
    int* cards;
    int numCards;
    double cash;

   public:
    Player(std::string name);
    void DrawCards(int numCards);
    int SumCards();
    bool AddCash(double cash);
    void StealCards(Player& account);
    void Report();
    std::string GetName();

    ~Player();

    void Debug();
};

#endif  // _PLAYER_H_
