/*PLEASE DON'T DELETE*/
//This file is create and written by Jiazheng Li 16212162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "disksPlacement.h"
#include "termination.h"

/*WARNING: THIS SUB-FUNCTION MUST! BE! USE! AFTER! REVERSI! FUNCTION!*/
void Termination_By_NoMoreEmptySpace (player player1, player player2 , disk board[SIZE][SIZE])
{
    /*First check board avaliablity by empty spcace*/
    int Empty_Sapce_Counter = 64;

    for (int Row_Counter = 0; Row_Counter <= 8; Row_Counter++)
    {
        for (int Column_Counter = 0; Column_Counter <= 8; Column_Counter++)
        {
            /*If board is not empty, count the disk*/
            if (board[Row_Counter][Column_Counter].type != NONE)
            {
                Empty_Sapce_Counter--;
            }
        }
    }
    
    /*If board empty space is 0, then announce the winner*/
    if (Empty_Sapce_Counter == 0)
    {
        printf("Player1 %s, points %d;\n",player1.name,player1.points);
        printf("Player2 %s, points %d;\n",player2.name,player1.points);
        
        printf("Game is over, there is no empty space.\n");
        
        if(player1.points > player2.points)
        {
            printf("The winner is %s\n",player1.name);
        }
        else if (player2.points > player1.points)
        {
            printf("The winner is %s\n",player2.name);
        }
        
        save_final_result (player1, player2);
    }
}
//This file is create and written by Jiazheng Li 16212162
