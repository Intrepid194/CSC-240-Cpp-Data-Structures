 

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip> 
#include <random>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::play()
{
	srand(time(0)); //set the random seed based on time.
    bool done = false;
    char player;
    if(rand()%2 == 0){
    	player = 'X';
    }
    else{
    	player = 'O';
    }
    displayBoard();

    //tournament loop here before while !done.
    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    
}

bool ticTacToe::isValidMove(int row, int col) const
{
  
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    
}

status ticTacToe::gameStatus()
{
    
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
