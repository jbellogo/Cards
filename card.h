#ifndef _CARD_H
#define _CARD_H

enum class Faces { NINE, TEN, JACK, QUEEN, KING, ACE, JOKER, NOFACE };

enum class Suits { CLUBS, HEARTS, Diamonds, Spades};

class Card {
int value;
Faces face;
Suit suit;

public:
virtual void getValue();
virtual void getSuit();
// virtual void setValue(); for the jokers
// You shouldnt be allowed to write onto a card. thats just weird.

};

std::ostream & operator<<( std::ostream & out, const Card & c ) {
        switch(c.getSuit()) {
        case Hearts:
                str = "H";
                break;
        case Diamonds:
                str = "D";
                break;
        case Spades:
                str = "S";
                break;
        case Clubs:
                str = "C";
        }
        out << str << c.getValue() << std::endl;
        return out;
}


#endif
