#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "card.h"

int MAX_IN_RESERVE = 1;

class PlayCard;

class Player : public Observer {
// *************** PRIVATE *******************
// piles of cards
Deck discard_pile;  // owns these decks
Deck draw_pile;     // owns these decks
Card [MAX_IN_RESERVE] reserve; // this way it can be null.

// observes
HydraModel &observed_subject;   // observes a HydraModel... particularly its central vec of decks.
// distills
std::vector<Cards> topsOfHeads; // hmm implement notify() and stuff

// more info
Card current_card;
int id, cardsToPlay;

std::shared_ptr<PlayCard> play_Card_strategy;

void setStrategy(int head_number) {
        // uses the strategy pattern to change the implementation of getCard
        if (head_number == 0 ) {
                *strategy = StratReserve(current_card);
        }
        if (topsOfHeads[head_number-1].getValue() == current_card.getValue()) {
                *strategy = StratSame(current_card);
        } else if (topsOfHeads[head_number-1].getValue() > current_card.getValue()) {
                // PlayCard.same()
                *strategy = StratLess(current_card);
        } else {
                throw;
                // throw("Bruh"); or smth
        }
}  // plays current_card on the head number.


// *************** PUBLIC  *******************

public:
// player superclass must have : hasWon(), lostRound(), playCard() methods.
bool hasWon();

void lostRound(); // instance of : lostRound => cuts head
void transferDiscardToDraw(); // shuffles then transfers
void PlayCard(int on_head_number) {
        setStrategy(on_head_number);
        this->strategy->makeMove();
        // what about all of the objecsts you need to change a decision. you can't pass everything!!
        // need to pass references to the center deck and the player decks!!! so that the algorith will be able to change them!!!
}
Card getFromDraft();
Card getFromDiscard();

};

class Human : public Player {
};
/*
   class Machine : public Player {
   };
 */

#endif
