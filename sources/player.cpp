
#include "player.hpp"
using namespace std;
#include <iostream>
#include <string>

namespace ariel
{
//constructor
Player::Player(std::string name)
{
    this->name = name;
}

int Player::stacksize()
{ 
    int numStart=26;
    return numStart;
}

int Player::cardesTaken()
{ 
    int numTake=0;
    return numTake;
}

}