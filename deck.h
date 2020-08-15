#ifndef _DECK_H
#define _DECK_H
#include "card.h"
#include <vector>
// game will have a stack of decks
// I will combine them by putting them in an big intermediary pile.
const int CARDS_IN_DECK = 52;

// should add an iterator ro smth?
class Deck {

int id = 0; // for calling them
std::vector<Card> vec; // or shared ptrs?

public:
Deck();
Deck(int id, int num_decks);
void shuffle();
int getId();
void draw();
void addCard();
int getSize();
Card getBack();

};
std::ostream & operator<<( std::ostream & out, const Deck & d );


#endif
