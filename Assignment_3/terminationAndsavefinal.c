/*PLEASE DON'T DELETE*/
//This file is create and written by Jiazheng Li 16212162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "disksPlacement.h"
#include "terminationAndsavefinal.h"

/*WARNING: THIS SUB-FUNCTION MUST! BE! USE! AFTER! REVERSI! FUNCTION!*/
//Sub-function for termination
int Termination (player player1, player player2 , disk board[SIZE][SIZE])
{
    //Termination result for control the while loop in main function
    int Termination_Control = 0;
    
    /*Count board empty spcace*/
    int Empty_Sapce_Counter = 64;

    for (int Row_Counter = 0; Row_Counter < 8; Row_Counter++)
    {
        for (int Column_Counter = 0; Column_Counter < 8; Column_Counter++)
        {
            /*If board is not empty, count the disk*/
            if (board[Row_Counter][Column_Counter].type != NONE)
            {
                Empty_Sapce_Counter--;
            }
        }
    }
    
    /*First situation: termination by no possible moves*/
    if (Empty_Sapce_Counter > 0)
    {
        //Counter to collect possible moves
        int Possible_position_check_counter = 0;
        
        //Collect possible moves from each person
        Possible_position_check_counter += Possible_position_check(player1.type, board);
        Possible_position_check_counter += Possible_position_check(player2.type, board);
        
//        DEBUG
//        printf("Debug possible counter: %d",Possible_position_check_counter);
        
        
        if (Possible_position_check_counter == 0)
        {
            printf("Game is over, there is no possible moves for both players.\n");
            
            printf("Player1 %s, points %d;\n",player1.name,player1.points);
            printf("Player2 %s, points %d;\n",player2.name,player1.points);
            
            if(player1.points > player2.points)
            {
                printf("The winner is %s\n",player1.name);
            }
            else if (player2.points > player1.points)
            {
                printf("The winner is %s\n",player2.name);
            }
            
            //Call the print final result
            Save_final_result (player1, player2);
            
            //After terminated control the
            Termination_Control += 3;
        }
        
        //one player don't have possible moves, pass to anthoer player
        else if (Possible_position_check(player1.type, board) == 0)
        {
            if (Possible_position_check(player2.type, board) > 0)
            {
                printf("No avaliable move for this player1, automatically pass move to next player\n");
                Termination_Control += 1;
            }
        }
        
        //one player don't have possible moves, pass to anthoer player
        else if (Possible_position_check(player2.type, board) == 0)
        {
            if (Possible_position_check(player1.type, board) > 0)
            {
                printf("No avaliable move for this player2, automatically pass move to next player\n");
                Termination_Control += 2;
            }
        }
    }
    
    /*Second situation: termination by no empty space*/
    else if (Empty_Sapce_Counter == 0)
    {
        printf("Game is over, there is no empty space.\n");
        
        printf("Player1 %s, points %d;\n",player1.name,player1.points);
        printf("Player2 %s, points %d;\n",player2.name,player1.points);
        
        if(player1.points > player2.points)
        {
            printf("The winner is %s\n",player1.name);
        }
        else if (player2.points > player1.points)
        {
            printf("The winner is %s\n",player2.name);
        }
        
        //Call the print final result
        Save_final_result (player1, player2);
        
        //After terminated control the 
        Termination_Control += 3;
    }
    
    return Termination_Control;
}

//Sub-function for termination sub-function to check possible position
int Possible_position_check (enum colour defiened_colour , disk board[SIZE][SIZE])
{
    //Counter for count whole valiable position
    int Valiable_postion_counter = 0;
    
   //Two for loop to check possible postion for every place on the board
    for (int Row_Counter = 0; Row_Counter < 8; Row_Counter++)
    {
        for (int Column_Counter = 0; Column_Counter < 8; Column_Counter++)
        {
            //check postion avaliablity
            if (board[Row_Counter][Column_Counter].type == NONE)
            {
                //diriction counter
                for (int dirction_counter = 0; dirction_counter < 8; dirction_counter++)
                {
                    int Row_checker = Row_Counter, Column_checker = Column_Counter;
                    
                    switch (dirction_counter)
                    {
                        case 0:
                            Column_checker -= 1;
                            while (Column_checker > 0)
                            {
                                /*
                                 if (board[Row_checker][Column_checker].type != NONE && board[Row_checker][Column_checker].type != defiened_colour)
                                 */
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker][Column_checker-1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Column_checker--;
                            }
                            break;
                        case 1:
                            Row_checker += 1;
                            Column_checker -= 1;
                            while (Row_checker < 8 && Column_checker > 0)
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker+1][Column_checker-1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker++;
                                Column_checker--;
                            }
                            break;
                        case 2:
                            Row_checker += 1;
                            while (Row_checker < 8 )
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker+1][Column_checker].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker++;
                            }
                            break;
                        case 3:
                            Row_checker += 1;
                            Column_checker += 1;
                            while (Row_checker < 8 && Column_checker < 8)
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker+1][Column_checker+1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker++;
                                Column_checker++;
                            }
                            break;
                        case 4:
                            Column_checker += 1;
                            while (Column_checker < 8)
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker][Column_checker+1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Column_checker++;
                            }
                            break;
                        case 5:
                            Row_checker -= 1;
                            Column_checker += 1;
                            while (Row_checker > 0 && Column_checker < 8)
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker-1][Column_checker+1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker--;
                                Column_checker++;
                            }
                            break;
                        case 6:
                            Row_checker -= 1;
                            while (Row_checker > 0 )
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker-1][Column_checker].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker--;
                            }
                            break;
                        case 7:
                            Row_checker -= 1;
                            Column_checker -= 1;
                            while (Row_checker > 0 && Column_checker > 0)
                            {
                                if (board[Row_checker][Column_checker].type == NONE)
                                {
                                    break;
                                }
                                else if(board[Row_checker][Column_checker].type != NONE)
                                {
                                    if (board[Row_checker][Column_checker].type != defiened_colour)
                                    {
                                        if (board[Row_checker-1][Column_checker-1].type == defiened_colour)
                                        {
                                            Valiable_postion_counter += 1;
                                        }
                                    }
                                }
                                Row_checker--;
                                Column_checker--;
                            }
                            break;
                    }
                }
            }
//            DeBug:
//            printf("%c %d |%d|\n",Row_Counter+'a',Column_Counter+1,Valiable_postion_counter);
        }
    }
    return Valiable_postion_counter;
}

//Sub-function of print the final result to a .txt file
void Save_final_result (player player1, player player2)
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
