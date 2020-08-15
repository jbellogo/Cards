#include "hydraModels.h"

HydraModel(int players) : turn{1}, players{players}, active_heads{1},
center_heads{std::make_shared<Deck>(0, players)} {
        center_heads->shuffle();
        // all cards from both decks at center pile.
        // ASSERT players > 0 SOMEWHERE
        // create the players, add them as observers
        for (int i = 1; i <= players; i++) {
                std::shared_ptr<Player> p = std::make_shared<Player>(i);
                p->initialize_draw_pile(center_heads[0], CARDS_IN_DECK/players);
                attach(p);
        }
        // the players get the cards.
        // First move (i.e. player 1 forced to move) is NOT MADE
}

bool HydraModel::gameOver() const {
        for (auto players& : observers) {
                if (players.hasWon()) return true;
        }
        return false;
}

// state
void HydraModel::printHeads(std::ostream & out) const {
        out << "Heads: " << std::endl;
        for (auto heads : center_heads) {
                out << heads; // outputting decks should be overwritten at this point
        }
        return out;
} // see specification

void HydraModel::printPlayers(std::ostream & out) const {
        out << "Players: " << std::endl;
        for (auto player : observers) {
                out << player;
        }
} // see specification

void HydraModel::addHead(Card c) {
        active_heads++;
        center_heads.push_back(std::make_shared<Deck>(active_heads));
        notify();
}
void HydraModel::addCardToHead(int index, Card &c){
        for (auto head : center_heads) {
                if (head.getId() == index) {
                        head.addCard(c);
                }
        }
        notify();
}

Deck &cutHead(int index) {
        std::erase(center_heads.begin()+index);
        notify()

}

// *************************************************************************************
// ************************THE GAME BREAD AND BUTTER************************************
// *************************************************************************************
/* The move is either the number of an active head, or 0. 0 refers to either placing the current card in
   reserve, or swapping the current card for the reserve card, depending on whether the player currently has a
   reserve card. If the player selects a head, but there is no valid move with that head, the game simply ignores
   the invalid move and prompts again. The same is true for a number greater than 0 but less than the first
   current head, or greater than the number of the last current head. If the card being placed is a joker, and a
   head has been selected, a further prompt requests “Joker value?”. The user must enter one of A, J, Q, K,
   or a number between 2 and 10, representing the value. If the entered value is not valid for the given play,
   then the play is ignored, and the player’s turn repeats. */

Card getHeadAt(int i) {
        return center_heads[i].getBack();
}


bool headIsActive(int at) {  // Helper
        for (auto deq : center_heads) {
                if (deq.getId() == at) {
                        return true;
                }
        }
        return false;
}



// Do the input output all from one place or you'll go crazy
bool isValidMove(int move_on_head_at) { /* Only a 0 or a head number is considered valid, HANDLES INPUT */
        if (move_on_head_at == 0 || headIsActive(move_on_head_at)) {
                return true;
        }
        if (current.getValue() <= center_heads[move_on_head_at-1]) { // if (you are allowed to move on it)
                return true
        }
        return false;
}


/*Note that cutting off a head is done by inputting
   the number of the first head, and this action is only valid when there is nowhere else the player can play
   their current card. In any case, the game updates the state of the cards according to the rules of Hydra, and
   either continues play or declares the player the winner.*/
void playerTurn(std::shared_ptr<Player> player) {
        // while there is cards left to play
        while (player.leftToPlay() != 0) {
                if (player.hasWon()) {
                        // do stuff maybe a class
                        std::cout << "YOUUUU WONNNN!" << '\n';
                        break;
                }
                printHeads();
                printPlayers();
                player.draw();
                out << "Player "<< player.getId() << ", you are holding a " << player.getCurrCard() << ". Your move?" << std::endl;
                int move_on_head_at;
                // get the move from user
                while (1) {
                        try {
                                in >> move_on_head_at;
                                if (isValidMove(move_on_head_at)) {
                                        break;
                                }
                        }
                }
                // make the move on datamodel
                playCard(move_on_head_at);
                // advance the loop
        }
        // change turns


}

void gameLoop(std::ostream &out, std::istream &in){
        // PLayer 1 draws, plays
        while (!gameOver()) {
                for (auto player : players_observering) {   // for each player
                        printHeads();
                        printPlayers();
                        out << "Player "<< player.getId(); << ", it is your turn." << std::endl;
                        player.playerTurn(); // starts another loop
                }
        }
}
