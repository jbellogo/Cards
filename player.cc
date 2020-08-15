#include "player.h"
#include <vector>

/*class Player : public Observer {
   int id, cardsToPlay;  // cards to play updated from the numbers of heads in HydraModel observed
   bool hasTurn;

   Deck discard_pile;  // owns this decks
   Deck draw_pile;     // owns this decks
   std::shared_ptr<Card> reserve; // this way it can be nullptr?
   std::shared_ptr<Card> current; // this way it can be nullptr?

   HydraModel &observed_subject;   // observes a HydraModel... particularly its central vec of decks.
   std::vector<Cards> heads; // hmm implement notify() and stuff
 */
void Player::notify( Subject & whoNotified ) {
        // update the heads. overwrite them.. thats is your LOCAL version
        int i= 0;
        // Just rewrite the entire thing
        for (auto card : heads) {
                card = whoNotified.getHeadAt(i);
                i++;
        }

}
void Player::notify(){
}

bool Player::hasWon() {
        return cardsTotal==0;
}
bool Player::canMove() {
        for (auto card : heads) {
                if (current->getValue() <= card.getValue()) {
                        return true;
                }
        }
        return false;

}

void initialize_draw_pile(Deck &from, int number_of_cards) {
        for (int i = 0; i<number_of_cards; i++) {
                drwaw_pilde.push_back(from.pop_back());
        }
} // if draw_pile empty transferDiscardToDraw() then draw

void Player::transferDiscardToDraw() {
        discard_pile->shuffle();
        discard_pile.swap(draw_pile); // idk if this alone does it

} // shuffles then transfers from discard to draw

void draw(){
        if (draw_pile.size() != 0) {
                current = draw_pile.pop_back();
        } else {
                transferDiscardToDraw();
                draw();
        }
}

//void setTurn(bool val); // ex fix
//bool hasTurn(); // { return hasTurn;}                                 // smth needs to update this
//std::shared_ptr<Card> draw(); // if draw_pile empty transferDiscardToDraw() then draw stored in var currnet right?

void handleReserve() {
        Card temp = reserve;
        reserve = current;
        current = temp; // could be nullptr
} // current with reserve

int getId() {
        return id;
}

Card getCurrCard(){
        return current;
}

// what about the moveToResearve()???
void playCard(int on_head_number) {
        current->setValue(std::cin, std::cout); // if you don't have a joker this doesnt do anything
        if (on_head_number == 0) {
                // move on reserve, turn doesnt advance
                player.handleReserve();
        } else if (heads[on_head_number-1].getFace() == Faces::ACE) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                player.advance(); // {cardsToPlay--}
        } else if (current.getValue() < heads[on_head_number-1].getValue()) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                player.advance(); // {cardsToPlay--}
        } else if (current.getValue() == heads[on_head_number-1]) {
                // can play
                observed_subject.addCardToHead(on_head_number, current);
                player.advance(); // {cardsToPlay--}
                setTurn(false); // ends turn
        } else {
                throw PlayException(); // or cut heads?
        }
}

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

// still need to declare it here, outside
std::ostream & operator<<( std::ostream & out, const Player & p ) {
        out << "Player " << id << ": "<< p.cardsTotal();
        out << "(" << p.cardsInDraw() << " draw, " << p.cardsInDiscard() << ")";
        if (hasTurn) {
                out << "+ 1 in hand, " << p.leftToPlay() << " remaining, " << p.inReserve()<< " in reserve ";
        }
        out << std::endl;
}

//class Human : public Player {};
