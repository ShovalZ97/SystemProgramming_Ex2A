#pragma once
#include <iostream>
#include <string>

namespace ariel
{
class Player
{
private:
    std::string name;
public:
    Player()
    {
        
    }
    Player(std::string name);
    //prints the amount of cards left.
    int stacksize(); 
    //prints the amount of cards this player has won.
    int cardesTaken();
};

}