#ifndef HYDRA_MODELS_
#define HYDRA_MODELS_


// Strategy pattern
class PlayCard {
// passed from PLayer at construction time
Card &card_to_play;
std::vector<Deck> &heads_at_center;  // or a vector of cards
Deck &draw_pile;
Deck &garbage_pile;

public:
virtual makeMove();
};


class StratLess : public PlayCard {
public:
override makeMove();

};
class StratSame : public PlayCard {
public:
override makeMove();

};
class StratReserve : public PlayCard {
public:
override makeMove();

};

#endif
