

#include <stdio.h>
#include <stdlib.h>
#include "disksAndPlayers.h"


//Heads from Jiazheng Li 16212162
#include "disksPlacement.h"
#include "terminationAndsavefinal.h"

#include "computePositions.h"

int main()
{
    player player1 = {"",BLACK,0};
    player player2 = {"",WHITE,0};
    
    // Variables declaration
    
    disk board[SIZE][SIZE];
    
//    initializePlayers(player1, player2);
    unsigned long nameSize;
    // Insert player 1
    printf("Player 1 please insert your name:   \n");
    fgets(player1.name, 20, stdin);
    nameSize = strlen(player1.name);
    player1.name[nameSize -1] = '\0';
    
    // Assign colours and points to player 1
    player1.type = BLACK;
    player1.points = 2;
    
    // Insert player 2
    printf("Player 2 please insert your name:   \n");
    fgets(player2.name, 20, stdin);
    nameSize = strlen(player2.name);
    player2.name[nameSize -1] = '\0';
    
    // Assign colours and points to player 2
    player2.type = WHITE;
    player2.points = 2;
    
    
    initializeBoard(board);
    
    printBoard(board);
    
    
    
    int termination_sign = 0;
    
    while (termination_sign != 3)
    {
        
        //For black
        if (termination_sign != 2)
        {
            computePositions_Black(board, player1);

            int White_Counter = 0,Black_Counter = 0;
            
            //for loop for counting
            for (int Row_Counter = 0; Row_Counter < 8; Row_Counter++)
            {
                for (int Column_Counter = 0; Column_Counter < 8; Column_Counter++)
                {
                    //If board is not empty, count the disk
                    if (board[Row_Counter][Column_Counter].type != NONE)
                    {
                        //count white disks
                        if(board[Row_Counter][Column_Counter].type == WHITE)
                        {
                            White_Counter++;
                        }
                        //count black disks
                        else if(board[Row_Counter][Column_Counter].type == BLACK)
                        {
                            Black_Counter++;
                        }
                    }
                }
            }
            
            //Renew player's points after reversi
            player1.points = Black_Counter;
            player2.points = White_Counter;

            printBoard(board);

        }
        
        termination_sign = Termination (player1, player2 , board);
        
        //For white
        if (termination_sign != 1 && termination_sign != 3)
        {
            computePositions_White(board, player2);
            
            
            int White_Counter = 0,Black_Counter = 0;
            
            //for loop for counting
            for (int Row_Counter = 0; Row_Counter < 8; Row_Counter++)
            {
                for (int Column_Counter = 0; Column_Counter < 8; Column_Counter++)
                {
                    //If board is not empty, count the disk
                    if (board[Row_Counter][Column_Counter].type != NONE)
                    {
                        //count white disks
                        if(board[Row_Counter][Column_Counter].type == WHITE)
                        {
                            White_Counter++;
                        }
                        //count black disks
                        else if(board[Row_Counter][Column_Counter].type == BLACK)
                        {
                            Black_Counter++;
                        }
                    }
                }
            }
            
            //Renew player's points after reversi
            player1.points = Black_Counter;
            player2.points = White_Counter;
            
            printBoard(board);
        }
        
        termination_sign = Termination (player1, player2 , board);
        
        printf("Terminate sign: %d",termination_sign);
//        Debug
//        printf("Debug %d",Possible_position_check(BLACK, board));
//        printf("Debug %d",Possible_position_check(WHITE, board));
        
    }
 
    puts("");

}

