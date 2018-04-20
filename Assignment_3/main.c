

#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"


//Heads from Jiazheng Li 16212162
#include "disksPlacement.h"
#include "terminationAndsavefinal.h"

#include "computePositions.h"

int main()
{
    // Variables declaration
    
    player player1= {"player1", BLACK,0};
    player player2= {"player2", WHITE,0};
    disk board[SIZE][SIZE];
    
    initializePlayers(player1, player2);
    
    initializeBoard(board);
    
    printBoard(board);
    
    int termination_sign = 0;
    
    while (termination_sign != 3)
    {
        
        //For black
        if (termination_sign == 1 || termination_sign == 0)
        {
            computePositions_Black(board, player1);

            Renew_Player_Points (player1, player2, board);

            printBoard(board);

        }
        
        termination_sign = Termination (player1, player2 , board);
        
        //For white
        if (termination_sign == 2 || termination_sign == 0)
        {
            computePositions_White(board, player2);
            
            Renew_Player_Points (player1, player2, board);
            
            printBoard(board);
        }
        
        termination_sign = Termination (player1, player2 , board);
        
      
//        Debug
//        printf("Debug %d",Possible_position_check(BLACK, board));
//        printf("Debug %d",Possible_position_check(WHITE, board));
        
    }
 
    puts("");

}
