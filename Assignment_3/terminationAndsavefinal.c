/*PLEASE DON'T DELETE*/
//This file is create and written by Jiazheng Li 16212162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "disksPlacement.h"
#include "terminationAndsavefinal.h"

/*WARNING: THIS SUB-FUNCTION MUST! BE! USE! AFTER! REVERSI! FUNCTION!*/
//Sub-function for termination by the condition of no more empty space
int Termination_By_NoMoreEmptySpace (player player1, player player2 , disk board[SIZE][SIZE])
{
    //Termination result for control the while loop in main function
    int Termination_Result = 0;
    
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
        
        //Call the print final result
        save_final_result (player1, player2);
        
        //After terminated control the 
        Termination_Result += 1;
    }
    return Termination_Result;
}

//Sub-function of print the final result to a .txt file
void save_final_result (player player1, player player2)
{
    FILE * cfPtr;
    
    if ((cfPtr=fopen("GameResult.txt", "w"))==NULL)
    {
        printf("Fail to open file GameResult.txt\n");
    }
    else
    {
        fprintf(cfPtr,"Player1 %s, points: %d\n",player1.name,player1.points);
        fprintf(cfPtr,"Player2 %s, points: %d\n",player2.name,player2.points);
        
        if (player1.points > player2.points)
        {
            fprintf(cfPtr,"The winner is %s\n\n",player1.name);
        }
        else if (player2.points > player1.points)
        {
            fprintf(cfPtr,"The winner is %s\n\n",player2.name);
        }
        else
        {
            fprintf(cfPtr,"This game is tied\n\n");
        }
        
        fclose(cfPtr);
    }
}
//This file is create and written by Jiazheng Li 16212162
