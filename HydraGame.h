#ifndef HYDRA_MODELS_
#define HYDRA_MODELS_


#include "HydraModels.h"

// Analogous to a Controller
class HydraGame {
// Its "model"
HydraModels &game;   // reference because you create it in main.
int players;
private:
// composition over inheritance, you don't create a Models object, just pass one by reference
HydraGame(int players, HydraModels &game) : game{game} {
}

gameLoop(){
        while (!game.isOver()) {
                //Play
                // Distribute decks
                game.nextTurn();
        }
}

};



#endif
