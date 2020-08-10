#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "card.h"

int MAX_ATA_TIME = 1;

class PlayCard;

class Player : public Observer {
// *************** PRIVATE *******************
//            ********* Atributes ************
// info
int id, cardsToPlay;  // cards to play updated from the numbers of heads in HydraModel observed
bool hasTurn;
// Card Models
Deck discard_pile;  // owns this decks
Deck draw_pile;     // owns this decks
std::shared_ptr<Card> reserve; // this way it can be null.
std::shared_ptr<Card> current; // this way it can be null.
// observes
HydraModel &observed_subject;   // observes a HydraModel... particularly its central vec of decks.
// distills
std::vector<Cards> heads; // hmm implement notify() and stuff

//            ********* Methods ************
// only friend operator>> calls these
int inReserve() {
        return reserve ? 1 : 0; // if nullptr
}
int leftToPlay() {
        return cardsToPlay;
}
int cardsInDraw(){
        return draw_pile.size();
}
int cardsInDiscard(){
        return discard_pile.size();
}
int cardsTotal(){
        return cardsInDraw()+ cardsInDiscard();
}
friend std::ostream &operator<<(std::ostream &out, const Player &p);

// *************** PUBLIC  *******************
public:
// player superclass must have : hasWon(), lostRound(), playCard() methods.
bool hasWon();
void lostRound(); // cuts head for HydraPlayer Concrete
void transferDiscardToDraw(); // shuffles then transfers

/*
 ****************
   METHODS for playerMoveLoop() in Hydra model
 ****************
 */
void setTurn(bool val); // ex fix
bool hasTurn(); // { return hasTurn;}                                 // smth needs to update this
Card draw(); // if draw_pile empty transferDiscardToDraw() then draw

// reserve moves
void putInReserve(shared_ptr<Card> c);
void switchWithReserve(); // current with reserve


// Let the man do his thing
playerMoveLoop() {

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

};

// still need to declare it here, outside
std::ostream & operator<<( std::ostream & out, const Player & p ) {
        out << "Player " << id << ": "<< p.cardsTotal();
        out << "(" << p.cardsInDraw() << " draw, " << p.cardsInDiscard() << ")";
        if (hasTurn) {
                out << "+ 1 in hand, " << p.leftToPlay() << " remaining, " << p.inReserve()<< " in reserve ";
        }
        out << std::endl;
}

// wrapper class...So we call Human? do we make Player abstract? think so
class Human : public Player {
};
/*
   class Machine : public Player {
   };
 */

#endif
