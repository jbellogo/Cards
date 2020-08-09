/*
 * Model class.  Is responsible keeping track of the deck of cards.
 * It knows nothing about views or controllers.
 */

#ifndef HYDRA_MODELS_
#define HYDRA_MODELS_

#include "subject.h"
#include "cards.h"

const int CARDS_IN_DECK = 52;

// State of the game
// Model provides the data and means/methods to manipulate it.
// we a subject
class HydraModels : public Subject {
// *************** PRIVATE *******************
std::vector<std::shared_ptr<Deck> > center_heads;
std::vector<std::shared_ptr<Player> > &players_observering;  // reference = this won't create the players, the HydraGame will have to do it.
int turn, players, heads;   // hella important these boyz

// *************** PUBLIC  *******************
public:
HydraModels(int players);  // this shoud initilize niceley.with each player with a deck
// all of these methods alter/inquire about the state... so no flow here.
void nextTurn();
bool isOver();

HydraGame(int num_of_players); // init

// state
void printHeads(); // see specification
void printPlayers(); // see specification

Player &getPlayerAt(int number);

void addHead();
void addCardToHead(int index);
Deck &cutHead();
void newPlayer();

}; // Model


#endif
