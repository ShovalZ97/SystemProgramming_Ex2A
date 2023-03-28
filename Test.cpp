#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("Before the game")
 {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    //before we start to every player has 26 cards in his stack size and 0 cards that player has won
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken()==0);

    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken()==0);

    //check that not return winner before the game start
    bool winner1 = game.printWiner()=="";
    CHECK(winner1);

    //check that there is no undone move before thr game start
    bool noLast = game.printLastTurn()=="";
    CHECK(noLast);

}
TEST_CASE("Lets start the game, After 1 turn") 
{
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Shoval");
    Game game(p1,p2); 

    //after 1 turn
    game.playTurn();

    //check if after 1 turn the last print turn and what print log return is equal
    bool printsEq=(game.printLastTurn())==(game.printLog());
    CHECK(printsEq);


    //check if the same player1 play
    bool check= true;
    try
    {
        Game game(p1,p1); 
    }
    catch(const std::exception& e)
    {
        check=false << '\n';
    }
    CHECK(check);

     //check if the same player 2 play
    bool check2= true;
    try
    {
        Game game(p2,p2); 
    }
    catch(const std::exception& e)
    {
        check2=false << '\n';
    }
    CHECK(check2);

    //after 1 turn , one of the players has least 25 cards in the stack size and if he is win
    //he has at least 2 cards
    bool turn1 = ((p1.stacksize() <= 25) &&(p1.cardesTaken()>=2) ) ||( (p2.stacksize() <= 25 )&&(p2.cardesTaken()>=2)) ;
    CHECK(turn1);

    //after 1 turn the sum of all the cards together need to stay 52
    bool lossCards = ((p1.stacksize() +p1.cardesTaken()+p2.stacksize() +p2.cardesTaken()==52)) ;
    CHECK(lossCards);

    //after 1 turn we have two options:
    //first: one of the players win in the turn so check that one of the players no has cards
    //two:draw - and in this turn the cards taken is 0 of both
    //so we check that after 1 turn , or two of them has 0 in cardsTaken or just one of them,
    //but no chance that which both have more than 0 cardsTaken after 1 turn
    bool zeroCards = ((p1.cardesTaken()==0||p2.cardesTaken()==0)||(p1.cardesTaken()==0&&p2.cardesTaken()==0)) ;
    CHECK(zeroCards);
 
    //after one game if we do 52 minus all cards withount one group it need to be equal
    CHECK(52-(p1.stacksize()+p1.cardesTaken()+p2.stacksize() )== p2.cardesTaken());

    //we make more 5 games
    for (size_t i = 0; i < 4; i++)
    {
        game.playTurn();
        //every turn we check that the stacksize is equal of the players
        CHECK(p1.stacksize()==p2.stacksize());
    }
    
    //after 5 turn , one of the players has least 21 cards in the stack size
    bool turn5 = ((p1.stacksize() <= 21)) ||( (p2.stacksize() <= 21 ));
    CHECK(turn5);

    //end the game
    game.playAll();

}
TEST_CASE("The game is end, let's check if we use all the cards and not stay cards in the heap of all the players") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 

    //end the game
    game.playAll();

    //after we end the game we check if there is moves and the string is not empty
    CHECK(game.printLastTurn()!="");

    //after we end the game we have winner so we check if it return the winner or if they are in draw
    CHECK(game.printWiner()!="");
   
    //after the game is end we check if the sum of cardstaken of two players are equal
    CHECK(p1.cardesTaken()+p2.cardesTaken()==52);

    ///we check that the stack size in the end of the game is empty 
    //And no one has any cards left to playAnd no one has any cards left to play
    CHECK(p1.stacksize()==0);
    CHECK(p2.stacksize()==0);
}


