#ifndef snakeNLadder_h
#define snakeNLadder_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//printBoard prints the board passed int the parameter in a 10x10 manner
void printBoard(int board[100]);
//setUpSnake adds the snake heads and snake tails into the hiddenBoard which is passed into the function byref. Output is the hiddenBoard filled with snake heads and tail
void setUpSnake(string (&hiddenBoard)[100]);
//setUpLadder adds the ladder top and ladder base into the hiddenBoard which is passe into the function byref. Output is the hiddenBoard filled with ladder tops and ladder bases
void setUpLadder(string (&hiddenBoard)[100]);
//numOfPlayerLeft takes the numOfPlayer which is inputted by the user and player array. The output is the number of players who haven't won the game yet.
int numOfPlayerLeft(int numOfPlayer , int *player);
//prints the game menu
void Menu();
//returns the value of dice roll. If dice roll is 6, dice will be rolled again.
int rollDice();
/*checkWinner checks if there is a player who recently just won. takes the numOfPlayer number and player array as input parameter. the output is the player array which is 
changed in the function. It checks if there is anyone in the player array who reached 100 (which is the winning condition of the game) and changes the player's value in the array
to the negative of their placement.
*/
void checkWinner(int numOfPlayer,int *player);
//printWinner prints the placements of the player when the game is finished. it takes the numOfPlayer number and player array as the input parameters.
void printWinner(int numOfPlayer, int * player);
/*checkHiddenBoard takes the player array, counter number, and hiddenBoard array as input parameters. It will check the current player's position to see whether or not they landed
on a snake or ladder. If yes, it changes the value in the player array accordingly and prints the surprise message to the player.
*/
void checkHiddenBoard( int * player , int counter, string hiddenBoard[]);
/* game function takes the number of player, the dynamic array player, a boolean flag, counter number in integer, a string input, integer temp, and the hiddenboard which contains
   string inputs, and run several times until the game finish or terminated by the user */
void game(int numOfPlayers, int *player, bool flag, int counter, string input, int temp, string hiddenBoard[]);


#endif
