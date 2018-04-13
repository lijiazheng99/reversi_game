/*PLEASE DON'T DELETE*/
//This file is create and written by Jiazheng Li 16212162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "disksPlacement.h"
#include "termination.h"
#include "SaveFinal.h"

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
            fprintf(cfPtr,"The winner is %s\n",player1.name);
        }
        else if (player2.points > player1.points)
        {
            fprintf(cfPtr,"The winner is %s\n",player2.name);
        }
        
        fclose(cfPtr);
    }
}




//This file is create and written by Jiazheng Li 16212162
