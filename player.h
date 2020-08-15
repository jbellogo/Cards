#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "card.h"
#include "observer.h"
#include "deck.h"
#include <memory>
#include "hydraModels.h"

class Deck;

class Player : public Observer {

int id, cardsToPlay;
bool hasTurn;

Deck discard_pile;  // owns this decks
Deck draw_pile;     // owns this decks
std::shared_ptr<Card> reserve; // this way it can be nullptr?
std::shared_ptr<Card> current; // this way it can be nullptr?

HydraModel &observed_subject;   // observes a HydraModel
std::vector<Card> heads; // local data updated

int inReserve();
int leftToPlay();
int cardsInDraw();
int cardsInDiscard();
int cardsTotal();
friend std::ostream &operator<<(std::ostream &out, const Player &p);

public:
Player(int id);

virtual void notify( Subject & whoNotified ) override;
virtual void notify() override;

bool hasWon();
bool canMove();
void cutHead(); // cuts head for HydraPlayer Concrete
void transferDiscardToDraw(); // shuffles then transfers

void initialize_draw_pile(Deck &from, int number_of_cards);

void handleReserve();
int getId();
Card getCurrCard();
void playCard(int on_head_number);

};
std::ostream & operator<<( std::ostream & out, const Player & p );

//class Human : public Player {};
/* class Machine : public Player {}; */

#endif
