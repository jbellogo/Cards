/*
 * Model class.  Is responsible keeping track of the deck of cards and notifying to player.
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
class HydraModel : public Subject {
// *************** PRIVATE *******************
std::vector<std::shared_ptr<Deck> > center_heads;
std::vector<std::shared_ptr<Player> > &players_observering;  // reference = this won't create the players, the HydraGame will have to do it.
int turn, players, heads;   // hella important these boyz

// *************** PUBLIC  *******************
public:
HydraModel(int players);  // this shoud initilize niceley.with each player with a deck
// all of these methods alter/inquire about the state... so no flow here.
void nextTurn();
bool isOver();

// state
void printHeads() {
} // see specification
void printPlayers() {
        for (auto player : players_observering) {
                out << player;
        }
} // see specification

Player &getPlayerAt(int number);

void addHead();
void addCardToHead(int index, Card &c);
Deck &cutHead();
//void newPlayer();

// *************************************************************************************
// *************************************************************************************
// *******************************THE GAME CORE*****************************************
// *************************************************************************************
// *************************************************************************************
/*
   The move is either the number of an active head, or 0. 0 refers to either placing the current card in
   reserve, or swapping the current card for the reserve card, depending on whether the player currently has a
   reserve card. If the player selects a head, but there is no valid move with that head, the game simply ignores
   the invalid move and prompts again. The same is true for a number greater than 0 but less than the first
   current head, or greater than the number of the last current head. If the card being placed is a joker, and a
   head has been selected, a further prompt requests “Joker value?”. The user must enter one of A, J, Q, K,
   or a number between 2 and 10, representing the value. If the entered value is not valid for the given play,
   then the play is ignored, and the player’s turn repeats. Note that cutting off a head is done by inputting
   the number of the first head, and this action is only valid when there is nowhere else the player can play
   their current card. In any case, the game updates the state of the cards according to the rules of Hydra, and
   either continues play or declares the player the winner.
 */

int getValidMove(std::istream &in) {
        int move_on_head_at;
        while (true) {
                try {
                        in >> move_on_head_at; // would fail if it were a non int
                        // break conditions
                }

        }
}

void playerMoveLoop(std::shared_ptr<Player> player) {

        printHeads();
        printPlayers();
        out << "Player "<< player.getId() << ", you are holding a " << player.getCurrCard() << ". Your move?" << std::endl;
        int action = validateNum(in);

}


// what about the moveToResearve()???
void PlayCard(int on_head_number) {
        current->setValue(std::cin, std::cout); // if you don't have a joker this doesnt do anything
        if (heads[on_head_number-1].getFace() == Faces::ACE) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                cardsToPlay--;
        } else if (current.getValue() < heads[on_head_number-1].getValue()) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                cardsToPlay--;
        } else if (current.getValue() == heads[on_head_number-1]) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                cardsToPlay--;
                setTurn(false); // ends turn
        } else {
                throw PlayException();
        }
}

void gameLoop(std::ostream &out){
        while (!this->isOver()) {
                for (auto player : players_observering) {   // for each player
                        printHeads();
                        printPlayers();
                        out << "Player "<< player.getId(); << ", it is your turn." << std::endl;

                        player.playerMoveLoop();
                        //this->nextTurn(); dont really need this?
                }
        }
}

void initGame(std::ostream &out, std::istream &in){
        /*
           When the game begins, Computer Hydra should prompt “How many players?”, input a number greater
           than 1, then start a game with that many players. Internally, it should then shuffle together the decks,
           distribute the cards evenly among the players, and even perform the first player’s move, removing their first
           card and starting a head
         */
        // firstSteps() {
        out << "How many players?" << std::endl;
        int num_of_players = validateNum(in);
        HydraModel &game = HydraModel(num_of_players);
        //}
        game.gameLoop(out);
}




}; // Model


#endif
