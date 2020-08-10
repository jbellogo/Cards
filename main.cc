


int validateNum(std::istream &in){
        int number;
        while (1) {
                try { // reading from input
                        in >> number;
                        if (in < 2) {
                                return 2;
                        }
                } catch (...) {
                }
        }
        return -1;
}

// this should go in Hydragame /// or call this class hydragame ... but then nothing separates data models from flow/ execution
// use iterator pattern
void initGame(std::ostream &out, std::istream &in){
        /*
           When the game begins, Computer Hydra should prompt “How many players?”, input a number greater
           than 1, then start a game with that many players. Internally, it should then shuffle together the decks,
           distribute the cards evenly among the players, and even perform the first player’s move, removing their first
           card and starting a head
         */
        // firstSteps() {
        out << "How many players?" << std::endl;
        int num_of_players = validateNum(in);
        HydraModel &game = HydraModel(num_of_players);
        //}
        game.gameLoop(out);
}


int main(int argc, char const *argv[]) {
        /* code */
        initGame();
        return 0;
}
