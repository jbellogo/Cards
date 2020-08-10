#ifndef _CARD_H
#define _CARD_H

enum class Faces { NINE, TEN, JACK, QUEEN, KING, ACE, JOKER, NOFACE };

enum class Suits { CLUBS, HEARTS, DIAMONDS, SPADES};

class Card {
int value;
Faces face;
Suit suit;

public:
int getValue();
Suits getSuit();
Faces getFace();
void setValue(std::ostream & out, std::istream & in) {
        if (getFace() == Faces::JOKER) {
                out << "Joker value?" << std::endl;
                in >> value;
        }
}
// You shouldnt be allowed to write onto a card. thats just weird.

};

std::ostream & operator<<( std::ostream & out, const Card & c ) {
        switch(c.getSuit()) {
        case Suits::HEARTS:
                str = "H";
                break;
        case Suits::DIAMONDS:
                str = "D";
                break;
        case Suits::SPADES:
                str = "S";
                break;
        case Suits::CLUBS:
                str = "C";
        }
        out << str << c.getValue() << std::endl;
        return out;
}


#endif
