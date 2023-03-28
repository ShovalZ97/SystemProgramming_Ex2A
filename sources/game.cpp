#include <string>
#include "game.hpp"
#include "player.hpp"
using namespace std;
#include <string>
#include <iostream>


namespace ariel
{
    //constructor
    Game::Game(Player player_1, Player player_2)
    {
        this->player_1 = player_1;
        this->player_2 = player_2;
    }
    void Game::playTurn()
    {

    }
    void Game::playAll()
    {

    }
    std::string Game::printLastTurn()
    {
        std::string lastTurn="";
        return lastTurn;
    }

    std::string Game::printLog()
    {
        std::string moveGame="";
        return moveGame;
    }

    std::string Game::printWiner()
    {
        std::string name ="";
        return name;
    }

    void Game::printStats()
    {

    }

}