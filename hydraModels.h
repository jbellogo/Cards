/*
 * Model class. Is responsible keeping track of the deck of cards and notifying to player.
 * Notifies with "notify()"
 */

#ifndef HYDRA_MODELS_
#define HYDRA_MODELS_

#include "subject.h"
#include "card.h"
#include "player.h"

// State of the game
// Model provides the data and means/methods to manipulate it.
class HydraModel : public Subject {
std::vector<std::shared_ptr<Deck> > center_heads;
int turn, players, active_heads;
//std::vector<std::shared_ptr<Player> > &players_observering; INHERITS THIS FROM OBSERVER
public:
HydraModel(int players);
bool gameOver();

// state
void printHeads();
void printPlayers();
void addHead();
void addCardToHead(int index, Card &c);
Deck &cutHead();

Card getHeadAt(int i);

// controllers
bool headIsActive(int at);
bool isValidMove(int move_on_head_at);
void playerTurn(std::shared_ptr<Player> player);

}; // Model


#endif
