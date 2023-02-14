// Player.cpp - function definitions for a player

#include "Player.h"

#include <cstdlib>

Player::Player(std::string name) {
    this->name = name;
    cash = 0.0;
    numCards = 0;
}

void Player::DrawCards(int numCards) {
    // delete[] cards;
    cards = new int[numCards];
    this->numCards = numCards;
    for (int i = 0; i < numCards; i++) {
        cards[i] = (rand() % 10) + 1;
    }

    // Debug();
}

int Player::SumCards() {
    int sum = 0;
    for (int i = 0; i < numCards; i++) {
        sum += cards[i];
    }
    return sum;
}

bool Player::AddCash(double cash) {
    this->cash += cash;
    return cash <= 0;
}

void Player::StealCards(Player& player) {
    if (this == &player) return;

    delete[] cards;
    numCards = player.numCards;
    cards = new int[numCards];
    for (int i = 0; i < numCards; i++) {
        cards[i] = player.cards[i];
    }
    // Debug();
    delete[] player.cards;
    player.numCards = 0;
    // player.Debug();
}

void Player::Report() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(0);
    std::cout << name << " has $" << cash << " left over." << std::endl;
}

std::string Player::GetName() {
    return name;
}

Player::~Player() {
    delete[] cards;
};

void Player::Debug() {
    std::cout << "\n------\nThe cards of " << name << " are now: ";
    for (int i = 0; i < numCards; i++) {
        std::cout << cards[i] << " ";
    }
    std::cout << "\n------\n";
}
