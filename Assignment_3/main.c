#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"
#define SIZE 8


int main()
{
    // Variables declaration

    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];

    initializePlayers(player1, player2);

    initializeBoard(board);

    printBoard(board);

    computePositions(board, player1, player2);
    //invoke a method that implements the game logic

    //invoke a method that prints the final result

}
