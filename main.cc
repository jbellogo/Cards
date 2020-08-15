/*
   When the game begins, Computer Hydra should prompt “How many players?”, input a number greater
   than 1, then start a game with that many players. Internally, it should then shuffle together the decks,
   distribute the cards evenly among the players, and even perform the first player’s move, removing their first
   card and starting a head
 */



int main(int argc, char const *argv[]) {
        /* SETUP */
        out << "How many players?" << std::endl; // could put in a game intro
        int num_of_players;
        while (1) {
                try {
                        in >> num_of_players;
                        if (num_of_players >=2) break;
                }
        }
        HydraModel &game = HydraModel(num_of_players); // this creates everything
        // player 1 moves,

        // game loop
        game.gameLoop(cout, cin);

        return 0;
}
