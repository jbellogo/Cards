#ifndef HYDRA_MODELS_
#define HYDRA_MODELS_
// **************************************************
// **************************************************
// **************************************************
// **************************************************
// THIS MODULE WILL BE ADDED LATER FOR GOOD STYLE RN ITS IN the models
// **************************************************
// **************************************************
// **************************************************
// **************************************************

#include "HydraModels.h"

// Analogous to a Controller
class HydraGame {
// Its "model"
HydraModels &game;   // reference because you create it in main.
int players;
private:
// composition over inheritance, you don't create a Models object, just pass one by reference, which is created in main
HydraGame(int players, HydraModels &game) : game{game} {
        //sets shit up
}


gameLoop(){
        while (!game.isOver()) {
                for (auto players : game.getPlayers()) {
                        player.playerMoveLoop(); // another loop, set up to catch some exceptions?
                        game.nextTurn();
                } // may need some type of iterator pattern?
        }
}

};



#endif
