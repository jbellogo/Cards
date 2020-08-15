#include "deck.h"
#include <vector>

// game will have a stack of decks
// I will combine them by putting them in an big intermediary pile.

/*
   static const Suits allSuits[] = { CLUBS, HEARTS, DIAMONDS, SPADES};
   static const Faces allFaces[] = { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
 */
/*
   int id; // for calling them
   std::vector<Card> vec; // or shared ptrs?
 */

Deck(int id) : id{id} {}

// For the main center one
Deck(int id, int num_decks) : id{id} {
        for (int j = 0; j < num_decks; j++) {   // number of decks
                for (const auto suit : Suits::allSuits) {   // per suite
                        for (const auto face : Faces::allFaces) {   // 14 essential cards
                                Card c{face,suit};
                                vec.push_back(c);
                                //std::cout << c <<std::endl;
                        }
                }
                Card c{JOKER, NOFACE};
                vec.push_back(c);
                vec.push_back(c);
        }
}

void shuffle() {
        std::random_shuffle(vec.begin(), vec.end());
}
int getId() {
        return id;
}
Card draw() {
        return vec.pop_back();
}
void addCard(Card &c){
        vec.push_back(c);
}

int getSize(){
        reutrn vec.size();
}
Card getBack(){
        return vec.back();
}

std::ostream & operator<<( std::ostream & out, const Deck & d ) {
        out << id << ": " << vec.back() << "(" << vec.size() << ")" << std::endl;
}
