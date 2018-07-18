#include "Game.h"

int main(int argc, char* argv[])
{
    /// Creates an instance of the class Game
    Game game(argc, argv);
    /// Starts the game
    return game.run();
}
