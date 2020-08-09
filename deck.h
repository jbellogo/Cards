#ifndef _CARD_H
#define _CARD_H
#include "card.h"

// game will have a stack of decks
const int CARDS_IN_DECK = 52;


class Deck {
std::vector<Card> vec; // or shared ptrs?
public:
void shuffle();
void draw();
void addCard();

};

#endif
