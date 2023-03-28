#pragma once
#include <iostream>
#include "player.hpp"
#include <string>

namespace ariel
{
    class Game
    {
    private:
        Player player_1;
        Player player_2;
    public:
        std::string to_string();
        // Constructors:
        Game(Player player_1,Player player_2);
        void playTurn();
        // print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
        std::string printLastTurn(); 
        //playes the game untill the end
        void playAll(); 
        //prints the name of the winning player
        std::string printWiner(); 
        //prints all the turns played one line per turn
        std::string printLog(); 
        //for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
        //Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws)
        void printStats();
    };
}