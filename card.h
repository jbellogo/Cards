#ifndef _CARD_H
#define _CARD_H

#include <iostream>

namespace Faces {
enum class Faces {
        ONE=1, TWO=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7,
        EIGHT=8, NINE=9, TEN=10, JACK=10, QUEEN=10, KING=10, ACE=10, NOFACE
};
static const Faces allFaces[] = {
        Faces::ONE, Faces::TWO, Faces::THREE, Faces::FOUR, Faces::FIVE, Faces::SIX, Faces::SEVEN,
        Faces::EIGHT, Faces::NINE, Faces::TEN, Faces::JACK, Faces::QUEEN, Faces::KING, Faces::ACE
};
}

namespace Suits {

enum class Suits { CLUBS, HEARTS, DIAMONDS, SPADES, JOKER};
static const Suits allSuits[] = { Suits::CLUBS, Suits::HEARTS, Suits::DIAMONDS, Suits::SPADES };
}

class Card {
int value;
Faces::Faces face;
Suits::Suits suit;

public:
Card(Faces::Faces face, Suits::Suits suit);
int getValue();
Suits::Suits getSuit();
Faces::Faces getFace();
// only if joker, or testing mode enabled.
void setValue(std::ostream & out, std::istream & in);
// You shouldnt be allowed to write onto a card. thats just weird.

};

std::ostream & operator<<( std::ostream & out, const Card & c );


#endif
