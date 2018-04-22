

#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"


//Heads from Jiazheng Li 16212162
#include "disksPlacement.h"
#include "terminationAndsavefinal.h"

#include "computePositions.h"

int Empty_Space_Counter_Function (disk board[SIZE][SIZE]);

int main()
{
    player player1 = {"Player1",NONE,0};
    player player2 = {"Player2",NONE,0};
    
    // Variables declaration
    
    disk board[SIZE][SIZE];
    
    initializePlayers(&player1, &player2);

    initializeBoard(board);
    
    printBoard(board);
    
    int termination_sign = 0;
    int turns = 80;

    
    while (termination_sign != 1)
    {
        int Empty_Space_Counter=0;
        
        //For black
        if (turns%2==0)
        {
            if (Possible_position_check(BLACK, board)>0)
            {
                computePositions_Black(board, player1);
                
                //printf("*Debug Points 1:%d Points 2:%d Total:%d\n",player1.points,player2.points,player1.points+player2.points);
                
                Renew_Player_Points (&player1, &player2, board);
                
                //printf("*Debug Points 1:%d Points 2:%d Total:%d\n",player1.points,player2.points,player1.points+player2.points);
                
                printBoard(board);
                
                turns-=1;
            }
        }
        
        //For white
        else if (turns%2==1)
        {
            if (Possible_position_check(WHITE, board)>0)
            {
                computePositions_White(board, player2);
                
                //printf("*Debug Points 1:%d Points 2:%d Total:%d\n",player1.points,player2.points,player1.points+player2.points);
                
                Renew_Player_Points (&player1, &player2, board);
                
                //printf("*Debug Points 1:%d Points 2:%d Total:%d\n",player1.points,player2.points,player1.points+player2.points);
                
                printBoard(board);
                
                turns-=1;
            }
        }
        
        Empty_Space_Counter=Empty_Space_Counter_Function(board);
        //printf("*Debug Black %d",Possible_position_check(BLACK, board));
        //printf("*Debug White %d",Possible_position_check(WHITE, board));
        
        if (Possible_position_check(BLACK, board)==0 && Possible_position_check(WHITE, board)==0)
        {
            termination_sign = Termination (player1, player2 , board, Empty_Space_Counter);
        }
        else if (Possible_position_check(BLACK, board)>0 && Possible_position_check(WHITE, board)==0)
        {
            turns++;
        }
        else if (Possible_position_check(BLACK, board)==0 && Possible_position_check(WHITE, board)>0)
        {
            turns++;
        }
    }
    puts("");
}

int Empty_Space_Counter_Function (disk board[SIZE][SIZE])
{
    int Empty_Space_Counter=0;
    for (int RowCounter=0; RowCounter<8; RowCounter++)
    {
        for (int ColumnCounter=0; ColumnCounter<8; ColumnCounter++)
        {
            if (board[RowCounter][ColumnCounter].type==NONE)
            {
                Empty_Space_Counter++;
            }
        }
    }
    //printf("*Debug Empty space:%d\n",Empty_Space_Counter);
    return Empty_Space_Counter;
}
