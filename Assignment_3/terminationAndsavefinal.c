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
int Termination (player player1, player player2 , disk board[SIZE][SIZE],int emptyspace)
{
    //Termination result for control the while loop in main function
    int Termination_Control = 0;
    
    /*First situation: termination by no possible moves*/
    if (emptyspace > 0)
    {
            printf("Game is over, there is no possible moves for both players.\n");
            
            printf("Player1 %s, points %d;\n",player1.name,player1.points);
            printf("Player2 %s, points %d;\n",player2.name,player2.points);
            
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
            Termination_Control += 1;
    }
    
    /*Second situation: termination by no empty space*/
    else if (emptyspace == 0)
    {
        printf("Game is over, there is no empty space.\n");
        
        printf("Player1 %s, points %d;\n",player1.name,player1.points);
        printf("Player2 %s, points %d;\n",player2.name,player2.points);
        
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
        Termination_Control += 1;
    }
    
    return Termination_Control;
}

//Sub-function for termination sub-function to check possible position
int Possible_position_check (enum colour defiened_colour , disk board[SIZE][SIZE])
{
    if (defiened_colour == BLACK)
    {
        /* variables to save column and row number */
        int row[30];
        int col[30];
        int counter = 0;
        
        /* initializing all elements to 10000 for better usage later on
         in the program  */
        for(int i = 0; i < 30; i++){
            row[i] = -1;
            col[i] = -1;
        }
        
        /* checking horizontally left to right */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == BLACK){
                    if(board[i][j+1].type == WHITE && board[i][j+2].type == NONE){
                        if(i >= 0 && i <= 7 && j+2 >= 0 && j+2 <= 7){
                            row[counter] = i;
                            col[counter] = j+2;
                            counter++;
                        }
                    }
                    else if(board[i][j+1].type == WHITE && board[i][j+2].type == WHITE && board[i][j+3].type == NONE){
                        if(i >= 0 && i <= 7 && j+3 >= 0 && j+3 <= 7){
                            row[counter] = i;
                            col[counter] = j + 3;
                            counter++;
                        }
                    }
                    else if(board[i][j+1].type == WHITE && board[i][j+2].type == WHITE && board[i][j+3].type == WHITE && board[i][j+4].type == NONE){
                        if(i >= 0 && i <= 7 && j+4 >= 0 && j+4 <= 7){
                            row[counter] = i;
                            col[counter] = j + 4;
                            counter++;
                        }
                    }
                    else if(board[i][j+1].type == WHITE && board[i][j+2].type == WHITE && board[i][j+3].type == WHITE && board[i][j+4].type == WHITE && board[i][j+5].type == NONE){
                        if(i >= 0 && i <= 7 && j+5 >= 0 && j+5 <= 7){
                            row[counter] = i;
                            col[counter] = j + 5;
                            counter++;
                        }
                    }
                    else if(board[i][j+1].type == WHITE && board[i][j+2].type == WHITE && board[i][j+3].type == WHITE && board[i][j+4].type == WHITE && board[i][j+5].type == WHITE && board[i][j+6].type == NONE){
                        if(i >= 0 && i <= 7 && j+6 >= 0 && j+6 <= 7){
                            row[counter] = i;
                            col[counter] = j + 6;
                            counter++;
                        }
                    }
                    else if(board[i][j+1].type == WHITE && board[i][j+2].type == WHITE && board[i][j+3].type == WHITE && board[i][j+4].type == WHITE && board[i][j+5].type == WHITE && board[i][j+6].type == WHITE && board[i][j+7].type == NONE){
                        if(i >= 0 && i <= 7 && j+7 >= 0 && j+7 <= 7){
                            row[counter] = i;
                            col[counter] = j + 7;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking horizontally right to left*/
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >=0; j--){
                if(board[i][j].type == BLACK){
                    if(board[i][j-1].type == WHITE && board[i][j-2].type == NONE){
                        if(i >= 0 && i <= 7 && j-2 >= 0 && j-2 <= 7){
                            row[counter] = i;
                            col[counter] = j - 2;
                            counter++;
                        }
                    }
                    else if(board[i][j-1].type == WHITE && board[i][j-2].type == WHITE && board[i][j-3].type == NONE){
                        if(i >= 0 && i <= 7 && j-3 >= 0 && j-3 <= 7){
                            row[counter] = i;
                            col[counter] = j - 3;
                            counter++;
                        }
                    }
                    else if(board[i][j-1].type == WHITE && board[i][j-2].type == WHITE && board[i][j-3].type == WHITE && board[i][j-4].type == NONE){
                        if(i >= 0 && i <= 7 && j-4 >= 0 && j-4 <= 7){
                            row[counter] = i;
                            col[counter] = j - 4;
                            counter++;
                        }
                    }
                    else if(board[i][j-1].type == WHITE && board[i][j-2].type == WHITE && board[i][j-3].type == WHITE && board[i][j-4].type == WHITE && board[i][j-5].type == NONE){
                        if(i >= 0 && i <= 7 && j-5 >= 0 && j-5 <= 7){
                            row[counter] = i;
                            col[counter] = j - 5;
                            counter++;
                        }
                    }
                    else if(board[i][j-1].type == WHITE && board[i][j-2].type == WHITE && board[i][j-3].type == WHITE && board[i][j-4].type == WHITE && board[i][j-5].type == WHITE && board[i][j-6].type == NONE){
                        if(i >= 0 && i <= 7 && j-6 >= 0 && j-6 <= 7){
                            row[counter] = i;
                            col[counter] = j - 6;
                            counter++;
                        }
                    }
                    else if(board[i][j-1].type == WHITE && board[i][j-2].type == WHITE && board[i][j-3].type == WHITE && board[i][j-4].type == WHITE && board[i][j-5].type == WHITE && board[i][j-6].type == WHITE && board[i][j-7].type == NONE){
                        if(i >= 0 && i <= 7 && j-7 >= 0 && j-7 <= 7){
                            row[counter] = i;
                            col[counter] = j - 7;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking vertically up-down */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[j][i].type == BLACK){
                    if(board[j+1][i].type == WHITE && board[j+2][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+2 >= 0 && j+2 <=7){
                            row[counter] = j + 2;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j+1][i].type == WHITE && board[j+2][i].type == WHITE && board[j+3][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+3 >= 0 && j+3 <=7){
                            row[counter] = j + 3;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j+1][i].type == WHITE && board[j+2][i].type == WHITE && board[j+3][i].type == WHITE && board[j+4][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+4 >= 0 && j+4 <=7){
                            row[counter] = j + 4;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j+1][i].type == WHITE && board[j+2][i].type == WHITE && board[j+3][i].type == WHITE && board[j+4][i].type == WHITE && board[j+5][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+5 >= 0 && j+5 <=7){
                            row[counter] = j + 5;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j+1][i].type == WHITE && board[j+2][i].type == WHITE && board[j+3][i].type == WHITE && board[j+4][i].type == WHITE && board[j+5][i].type == WHITE && board[j+6][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+6 >= 0 && j+6 <=7){
                            row[counter] = j + 6;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j+1][i].type == WHITE && board[j+2][i].type == WHITE && board[j+3][i].type == WHITE && board[j+4][i].type == WHITE && board[j+5][i].type == WHITE && board[j+6][i].type == WHITE && board[j+7][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+7 >= 0 && j+7 <=7){
                            row[counter] = j + 7;
                            col[counter] = i;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking vertically down-up */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[j][i].type == BLACK){
                    if(board[j-1][i].type == WHITE && board[j-2][i].type == NONE){
                        if(i >= 0 && i <=7 && j-2 >= 0 && j-2 <= 7){
                            row[counter] = j - 2;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j-1][i].type == WHITE && board[j-2][i].type == WHITE && board[j-3][i].type == NONE){
                        if(i >= 0 && i <=7 && j-3 >= 0 && j-3 <= 7){
                            row[counter] = j - 3;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j-1][i].type == WHITE && board[j-2][i].type == WHITE && board[j-3][i].type == WHITE && board[j-4][i].type == NONE){
                        if(i >= 0 && i <=7 && j-4 >= 0 && j-4 <= 7){
                            row[counter] = j - 4;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j-1][i].type == WHITE && board[j-2][i].type == WHITE && board[j-3][i].type == WHITE && board[j-4][i].type == WHITE && board[j-5][i].type == NONE){
                        if(i >= 0 && i <=7 && j-5 >= 0 && j-5 <= 7){
                            row[counter] = j - 5;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j-1][i].type == WHITE && board[j-2][i].type == WHITE && board[j-3][i].type == WHITE && board[j-4][i].type == WHITE && board[j-5][i].type == WHITE && board[j-6][i].type == NONE){
                        if(i >= 0 && i <=7 && j-6 >= 0 && j-6 <= 7){
                            row[counter] = j - 6;
                            col[counter] = i;
                            counter++;
                        }
                    }
                    else if(board[j-1][i].type == WHITE && board[j-2][i].type == WHITE && board[j-3][i].type == WHITE && board[j-4][i].type == WHITE && board[j-5][i].type == WHITE && board[j-6][i].type == WHITE && board[j-7][i].type == NONE){
                        if(i >= 0 && i <=7 && j-7 >= 0 && j-7 <= 7){
                            row[counter] = j - 7;
                            col[counter] = i;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking left to right diagonally */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == BLACK){
                    if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == NONE){
                        if(i-2 >= 0 && i-2 <= 7 && j+2 >= 0 && j+2 <= 7){
                            row[counter] = i - 2;
                            col[counter] = j + 2;
                            counter++;
                        }
                    }
                    else if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == WHITE && board[i-3][j+3].type == NONE){
                        if(i-3 >= 0 && i-3 <= 7 && j+3 >= 0 && j+3 <= 7){
                            row[counter] = i - 3;
                            col[counter] = j + 3;
                            counter++;
                        }
                    }
                    else if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == WHITE && board[i-3][j+3].type == WHITE && board[i-4][j+4].type == NONE){
                        if(i-4 >= 0 && i-4 <= 7 && j+4 >= 0 && j+4 <= 7){
                            row[counter] = i - 4;
                            col[counter] = j + 4;
                            counter++;
                        }
                    }
                    else if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == WHITE && board[i-3][j+3].type == WHITE && board[i-4][j+4].type == WHITE && board[i-5][j+5].type == NONE){
                        if(i-5 >= 0 && i-5 <= 7 && j+5 >= 0 && j+5 <= 7){
                            row[counter] = i - 5;
                            col[counter] = j + 5;
                            counter++;
                        }
                    }
                    else if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == WHITE && board[i-3][j+3].type == WHITE && board[i-4][j+4].type == WHITE && board[i-5][j+5].type == WHITE && board[i-6][j+6].type == NONE){
                        if(i-6 >= 0 && i-6 <= 7 && j+6 >= 0 && j+6 <= 7){
                            row[counter] = i - 6;
                            col[counter] = j + 6;
                            counter++;
                        }
                    }
                    else if(board[i-1][j+1].type == WHITE && board[i-2][j+2].type == WHITE && board[i-3][j+3].type == WHITE && board[i-4][j+4].type == WHITE && board[i-5][j+5].type == WHITE && board[i-6][j+6].type == WHITE && board[i-7][j+7].type == NONE){
                        if(i-7 >= 0 && i-7 <= 7 && j+7 >= 0 && j+7 <= 7){
                            row[counter] = i - 7;
                            col[counter] = j + 7;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking right to left diagonally */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[i][j].type == BLACK){
                    if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == NONE){
                        if(i+2 >= 0 && i+2 <= 7 && j-2 >= 0 && j-2 <= 7){
                            row[counter] = i + 2;
                            col[counter] = j - 2;
                            counter++;
                        }
                    }
                    else if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == WHITE && board[i+3][j-3].type == NONE){
                        if(i+3 >= 0 && i+3 <= 7 && j-3 >= 0 && j-3 <= 7){
                            row[counter] = i + 3;
                            col[counter] = j - 3;
                            counter++;
                        }
                    }
                    else if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == WHITE && board[i+3][j-3].type == WHITE && board[i+4][j-4].type == NONE){
                        if(i+4 >= 0 && i+4 <= 7 && j-4 >= 0 && j-4 <= 7){
                            row[counter] = i + 4;
                            col[counter] = j - 4;
                            counter++;
                        }
                    }
                    else if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == WHITE && board[i+3][j-3].type == WHITE && board[i+4][j-4].type == WHITE && board[i+5][j-5].type == NONE){
                        if(i+5 >= 0 && i+5 <= 7 && j-5 >= 0 && j-5 <= 7){
                            row[counter] = i + 5;
                            col[counter] = j - 5;
                            counter++;
                        }
                    }
                    else if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == WHITE && board[i+3][j-3].type == WHITE && board[i+4][j-4].type == WHITE && board[i+5][j-5].type == WHITE && board[i+6][j-6].type == NONE){
                        if(i+6 >= 0 && i+6 <= 7 && j-6 >= 0 && j-6 <= 7){
                            row[counter] = i + 6;
                            col[counter] = j - 6;
                            counter++;
                        }
                    }
                    else if(board[i+1][j-1].type == WHITE && board[i+2][j-2].type == WHITE && board[i+3][j-3].type == WHITE && board[i+4][j-4].type == WHITE && board[i+5][j-5].type == WHITE && board[i+6][j-6].type == WHITE && board[i+7][j-7].type == NONE){
                        if(i+7 >= 0 && i+7 <= 7 && j-7 >= 0 && j-7 <= 7){
                            row[counter] = i + 7;
                            col[counter] = j - 7;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking up-down diagonally */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == BLACK){
                    if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == NONE){
                        if(i+2 >= 0 && i+2 <=7 && j+2 >= 0 && j+2 <=7){
                            row[counter] = i + 2;
                            col[counter] = j + 2;
                            counter++;
                        }
                    }
                    else if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == WHITE && board[i+3][j+3].type == NONE){
                        if(i+3 >= 0 && i+3 <=7 && j+3 >= 0 && j+3 <=7){
                            row[counter] = i + 3;
                            col[counter] = j + 3;
                            counter++;
                        }
                    }
                    else if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == WHITE && board[i+3][j+3].type == WHITE && board[i+4][j+4].type == NONE){
                        if(i+4 >= 0 && i+4 <=7 && j+4 >= 0 && j+4 <=7){
                            row[counter] = i + 4;
                            col[counter] = j + 4;
                            counter++;
                        }
                    }
                    else if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == WHITE && board[i+3][j+3].type == WHITE && board[i+4][j+4].type == WHITE && board[i+5][j+5].type == NONE){
                        if(i+5 >= 0 && i+5 <=7 && j+5 >= 0 && j+5 <=7){
                            row[counter] = i + 5;
                            col[counter] = j + 5;
                            counter++;
                        }
                    }
                    else if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == WHITE && board[i+3][j+3].type == WHITE && board[i+4][j+4].type == WHITE && board[i+5][j+5].type == WHITE && board[i+6][j+6].type == NONE){
                        if(i+6 >= 0 && i+6 <=7 && j+6 >= 0 && j+6 <=7){
                            row[counter] = i + 6;
                            col[counter] = j + 6;
                            counter++;
                        }
                    }
                    else if(board[i+1][j+1].type == WHITE && board[i+2][j+2].type == WHITE && board[i+3][j+3].type == WHITE && board[i+4][j+4].type == WHITE && board[i+5][j+5].type == WHITE && board[i+6][j+6].type == WHITE && board[i+7][j+7].type == NONE){
                        if(i+7 >= 0 && i+7 <=7 && j+7 >= 0 && j+7 <=7){
                            row[counter] = i + 7;
                            col[counter] = j + 7;
                            counter++;
                        }
                    }
                }
            }
        }
        
        /* checking down-up diagonally */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[i][j].type == BLACK){
                    if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == NONE){
                        if(i-2 >= 0 && i-2 <= 7 && j-2 >= 0 && j-2 <=7){
                            row[counter] = i - 2;
                            col[counter] = j - 2;
                            counter++;
                        }
                    }
                    else if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == WHITE && board[i-3][j-3].type == NONE){
                        if(i-3 >= 0 && i-3 <= 7 && j-3 >= 0 && j-3 <=7){
                            row[counter] = i - 3;
                            col[counter] = j - 3;
                            counter++;
                        }
                    }
                    else if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == WHITE && board[i-3][j-3].type == WHITE && board[i-4][j-4].type == NONE){
                        if(i-4 >= 0 && i-4 <= 7 && j-4 >= 0 && j-4 <=7){
                            row[counter] = i - 4;
                            col[counter] = j - 4;
                            counter++;
                        }
                    }
                    else if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == WHITE && board[i-3][j-3].type == WHITE && board[i-4][j-4].type == WHITE && board[i-5][j-5].type == NONE){
                        if(i-5 >= 0 && i-5 <= 7 && j-5 >= 0 && j-5 <=7){
                            row[counter] = i - 5;
                            col[counter] = j - 5;
                            counter++;
                        }
                    }
                    else if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == WHITE && board[i-3][j-3].type == WHITE && board[i-4][j-4].type == WHITE && board[i-5][j-5].type == WHITE && board[i-6][j-6].type == NONE){
                        if(i-6 >= 0 && i-6 <= 7 && j-6 >= 0 && j-6 <=7){
                            row[counter] = i - 6;
                            col[counter] = j - 6;
                            counter++;
                        }
                    }
                    else if(board[i-1][j-1].type == WHITE && board[i-2][j-2].type == WHITE && board[i-3][j-3].type == WHITE && board[i-4][j-4].type == WHITE && board[i-5][j-5].type == WHITE && board[i-6][j-6].type == WHITE && board[i-7][j-7].type == NONE){
                        if(i-7 >= 0 && i-7 <= 7 && j-7 >= 0 && j-7 <=7){
                            row[counter] = i - 7;
                            col[counter] = j - 7;
                            counter++;
                        }
                    }
                }
            }
        }
        return counter;
    }
    
    else if(defiened_colour == WHITE)
    {
        /* variables to save column and row number */
        int row1[30];
        int col1[30];
        int counter1 = 0;
        
        /* initializing all elements to -1 for better usage later on
         in the program  */
        for(int i = 0; i < 30; i++){
            row1[i] = -1;
            col1[i] = -1;
        }
        
        /* checking horizontally left to right */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == WHITE){
                    if(board[i][j+1].type == BLACK && board[i][j+2].type == NONE){
                        if(i >= 0 && i <= 7 && j+2 >= 0 && j+2 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j+2;
                            counter1++;
                        }
                    }
                    else if(board[i][j+1].type == BLACK && board[i][j+2].type == BLACK && board[i][j+3].type == NONE){
                        if(i >= 0 && i <= 7 && j+3 >= 0 && j+3 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j + 3;
                            counter1++;
                        }
                    }
                    else if(board[i][j+1].type == BLACK && board[i][j+2].type == BLACK && board[i][j+3].type == BLACK && board[i][j+4].type == NONE){
                        if(i >= 0 && i <= 7 && j+4 >= 0 && j+4 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j + 4;
                            counter1++;
                        }
                    }
                    else if(board[i][j+1].type == BLACK && board[i][j+2].type == BLACK && board[i][j+3].type == BLACK && board[i][j+4].type == BLACK && board[i][j+5].type == NONE){
                        if(i >= 0 && i <= 7 && j+5 >= 0 && j+5 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j + 5;
                            counter1++;
                        }
                    }
                    else if(board[i][j+1].type == BLACK && board[i][j+2].type == BLACK && board[i][j+3].type == BLACK && board[i][j+4].type == BLACK && board[i][j+5].type == BLACK && board[i][j+6].type == NONE){
                        if(i >= 0 && i <= 7 && j+6 >= 0 && j+6 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j + 6;
                            counter1++;
                        }
                    }
                    else if(board[i][j+1].type == BLACK && board[i][j+2].type == BLACK && board[i][j+3].type == BLACK && board[i][j+4].type == BLACK && board[i][j+5].type == BLACK && board[i][j+6].type == BLACK && board[i][j+7].type == NONE){
                        if(i >= 0 && i <= 7 && j+7 >= 0 && j+7 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j + 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking horizontally right to left*/
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >=0; j--){
                if(board[i][j].type == WHITE){
                    if(board[i][j-1].type == BLACK && board[i][j-2].type == NONE){
                        if(i >= 0 && i <= 7 && j-2 >= 0 && j-2 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 2;
                            counter1++;
                        }
                    }
                    else if(board[i][j-1].type == BLACK && board[i][j-2].type == BLACK && board[i][j-3].type == NONE){
                        if(i >= 0 && i <= 7 && j-3 >= 0 && j-3 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 3;
                            counter1++;
                        }
                    }
                    else if(board[i][j-1].type == BLACK && board[i][j-2].type == BLACK && board[i][j-3].type == BLACK && board[i][j-4].type == NONE){
                        if(i >= 0 && i <= 7 && j-4 >= 0 && j-4 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 4;
                            counter1++;
                        }
                    }
                    else if(board[i][j-1].type == BLACK && board[i][j-2].type == BLACK && board[i][j-3].type == BLACK && board[i][j-4].type == BLACK && board[i][j-5].type == NONE){
                        if(i >= 0 && i <= 7 && j-5 >= 0 && j-5 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 5;
                            counter1++;
                        }
                    }
                    else if(board[i][j-1].type == BLACK && board[i][j-2].type == BLACK && board[i][j-3].type == BLACK && board[i][j-4].type == BLACK && board[i][j-5].type == BLACK && board[i][j-6].type == NONE){
                        if(i >= 0 && i <= 7 && j-6 >= 0 && j-6 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 6;
                            counter1++;
                        }
                    }
                    else if(board[i][j-1].type == BLACK && board[i][j-2].type == BLACK && board[i][j-3].type == BLACK && board[i][j-4].type == BLACK && board[i][j-5].type == BLACK && board[i][j-6].type == BLACK && board[i][j-7].type == NONE){
                        if(i >= 0 && i <= 7 && j-7 >= 0 && j-7 <= 7){
                            row1[counter1] = i;
                            col1[counter1] = j - 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking vertically up-down */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[j][i].type == WHITE){
                    if(board[j+1][i].type == BLACK && board[j+2][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+2 >= 0 && j+2 <=7){
                            row1[counter1] = j + 2;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j+1][i].type == BLACK && board[j+2][i].type == BLACK && board[j+3][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+3 >= 0 && j+3 <=7){
                            row1[counter1] = j + 3;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j+1][i].type == BLACK && board[j+2][i].type == BLACK && board[j+3][i].type == BLACK && board[j+4][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+4 >= 0 && j+4 <=7){
                            row1[counter1] = j + 4;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j+1][i].type == BLACK && board[j+2][i].type == BLACK && board[j+3][i].type == BLACK && board[j+4][i].type == BLACK && board[j+5][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+5 >= 0 && j+5 <=7){
                            row1[counter1] = j + 5;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j+1][i].type == BLACK && board[j+2][i].type == BLACK && board[j+3][i].type == BLACK && board[j+4][i].type == BLACK && board[j+5][i].type == BLACK && board[j+6][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+6 >= 0 && j+6 <=7){
                            row1[counter1] = j + 6;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j+1][i].type == BLACK && board[j+2][i].type == BLACK && board[j+3][i].type == BLACK && board[j+4][i].type == BLACK && board[j+5][i].type == BLACK && board[j+6][i].type == BLACK && board[j+7][i].type == NONE){
                        if(i >= 0 && i <= 7 && j+7 >= 0 && j+7 <=7){
                            row1[counter1] = j + 7;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking vertically down-up */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[j][i].type == WHITE){
                    if(board[j-1][i].type == BLACK && board[j-2][i].type == NONE){
                        if(i >= 0 && i <=7 && j-2 >= 0 && j-2 <= 7){
                            row1[counter1] = j - 2;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j-1][i].type == BLACK && board[j-2][i].type == BLACK && board[j-3][i].type == NONE){
                        if(i >= 0 && i <=7 && j-3 >= 0 && j-3 <= 7){
                            row1[counter1] = j - 3;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j-1][i].type == BLACK && board[j-2][i].type == BLACK && board[j-3][i].type == BLACK && board[j-4][i].type == NONE){
                        if(i >= 0 && i <=7 && j-4 >= 0 && j-4 <= 7){
                            row1[counter1] = j - 4;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j-1][i].type == BLACK && board[j-2][i].type == BLACK && board[j-3][i].type == BLACK && board[j-4][i].type == BLACK && board[j-5][i].type == NONE){
                        if(i >= 0 && i <=7 && j-5 >= 0 && j-5 <= 7){
                            row1[counter1] = j - 5;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j-1][i].type == BLACK && board[j-2][i].type == BLACK && board[j-3][i].type == BLACK && board[j-4][i].type == BLACK && board[j-5][i].type == BLACK && board[j-6][i].type == NONE){
                        if(i >= 0 && i <=7 && j-6 >= 0 && j-6 <= 7){
                            row1[counter1] = j - 6;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                    else if(board[j-1][i].type == BLACK && board[j-2][i].type == BLACK && board[j-3][i].type == BLACK && board[j-4][i].type == BLACK && board[j-5][i].type == BLACK && board[j-6][i].type == BLACK && board[j-7][i].type == NONE){
                        if(i >= 0 && i <=7 && j-7 >= 0 && j-7 <= 7){
                            row1[counter1] = j - 7;
                            col1[counter1] = i;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking left to right diagonally */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == WHITE){
                    if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == NONE){
                        if(i-2 >= 0 && i-2 <= 7 && j+2 >= 0 && j+2 <= 7){
                            row1[counter1] = i - 2;
                            col1[counter1] = j + 2;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == BLACK && board[i-3][j+3].type == NONE){
                        if(i-3 >= 0 && i-3 <= 7 && j+3 >= 0 && j+3 <= 7){
                            row1[counter1] = i - 3;
                            col1[counter1] = j + 3;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == BLACK && board[i-3][j+3].type == BLACK && board[i-4][j+4].type == NONE){
                        if(i-4 >= 0 && i-4 <= 7 && j+4 >= 0 && j+4 <= 7){
                            row1[counter1] = i - 4;
                            col1[counter1] = j + 4;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == BLACK && board[i-3][j+3].type == BLACK && board[i-4][j+4].type == BLACK && board[i-5][j+5].type == NONE){
                        if(i-5 >= 0 && i-5 <= 7 && j+5 >= 0 && j+5 <= 7){
                            row1[counter1] = i - 5;
                            col1[counter1] = j + 5;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == BLACK && board[i-3][j+3].type == BLACK && board[i-4][j+4].type == BLACK && board[i-5][j+5].type == BLACK && board[i-6][j+6].type == NONE){
                        if(i-6 >= 0 && i-6 <= 7 && j+6 >= 0 && j+6 <= 7){
                            row1[counter1] = i - 6;
                            col1[counter1] = j + 6;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j+1].type == BLACK && board[i-2][j+2].type == BLACK && board[i-3][j+3].type == BLACK && board[i-4][j+4].type == BLACK && board[i-5][j+5].type == BLACK && board[i-6][j+6].type == BLACK && board[i-7][j+7].type == NONE){
                        if(i-7 >= 0 && i-7 <= 7 && j+7 >= 0 && j+7 <= 7){
                            row1[counter1] = i - 7;
                            col1[counter1] = j + 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking right to left diagonally */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[i][j].type == WHITE){
                    if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == NONE){
                        if(i+2 >= 0 && i+2 <= 7 && j-2 >= 0 && j-2 <= 7){
                            row1[counter1] = i + 2;
                            col1[counter1] = j - 2;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == BLACK && board[i+3][j-3].type == NONE){
                        if(i+3 >= 0 && i+3 <= 7 && j-3 >= 0 && j-3 <= 7){
                            row1[counter1] = i + 3;
                            col1[counter1] = j - 3;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == BLACK && board[i+3][j-3].type == BLACK && board[i+4][j-4].type == NONE){
                        if(i+4 >= 0 && i+4 <= 7 && j-4 >= 0 && j-4 <= 7){
                            row1[counter1] = i + 4;
                            col1[counter1] = j - 4;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == BLACK && board[i+3][j-3].type == BLACK && board[i+4][j-4].type == BLACK && board[i+5][j-5].type == NONE){
                        if(i+5 >= 0 && i+5 <= 7 && j-5 >= 0 && j-5 <= 7){
                            row1[counter1] = i + 5;
                            col1[counter1] = j - 5;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == BLACK && board[i+3][j-3].type == BLACK && board[i+4][j-4].type == BLACK && board[i+5][j-5].type == BLACK && board[i+6][j-6].type == NONE){
                        if(i+6 >= 0 && i+6 <= 7 && j-6 >= 0 && j-6 <= 7){
                            row1[counter1] = i + 6;
                            col1[counter1] = j - 6;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j-1].type == BLACK && board[i+2][j-2].type == BLACK && board[i+3][j-3].type == BLACK && board[i+4][j-4].type == BLACK && board[i+5][j-5].type == BLACK && board[i+6][j-6].type == BLACK && board[i+7][j-7].type == NONE){
                        if(i+7 >= 0 && i+7 <= 7 && j-7 >= 0 && j-7 <= 7){
                            row1[counter1] = i + 7;
                            col1[counter1] = j - 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking up-down diagonally */
        for(int i = 0; i <=7; i++){
            for(int j = 0; j <=7; j++){
                if(board[i][j].type == WHITE){
                    if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == NONE){
                        if(i+2 >= 0 && i+2 <=7 && j+2 >= 0 && j+2 <=7){
                            row1[counter1] = i + 2;
                            col1[counter1] = j + 2;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == BLACK && board[i+3][j+3].type == NONE){
                        if(i+3 >= 0 && i+3 <=7 && j+3 >= 0 && j+3 <=7){
                            row1[counter1] = i + 3;
                            col1[counter1] = j + 3;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == BLACK && board[i+3][j+3].type == BLACK && board[i+4][j+4].type == NONE){
                        if(i+4 >= 0 && i+4 <=7 && j+4 >= 0 && j+4 <=7){
                            row1[counter1] = i + 4;
                            col1[counter1] = j + 4;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == BLACK && board[i+3][j+3].type == BLACK && board[i+4][j+4].type == BLACK && board[i+5][j+5].type == NONE){
                        if(i+5 >= 0 && i+5 <=7 && j+5 >= 0 && j+5 <=7){
                            row1[counter1] = i + 5;
                            col1[counter1] = j + 5;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == BLACK && board[i+3][j+3].type == BLACK && board[i+4][j+4].type == BLACK && board[i+5][j+5].type == BLACK && board[i+6][j+6].type == NONE){
                        if(i+6 >= 0 && i+6 <=7 && j+6 >= 0 && j+6 <=7){
                            row1[counter1] = i + 6;
                            col1[counter1] = j + 6;
                            counter1++;
                        }
                    }
                    else if(board[i+1][j+1].type == BLACK && board[i+2][j+2].type == BLACK && board[i+3][j+3].type == BLACK && board[i+4][j+4].type == BLACK && board[i+5][j+5].type == BLACK && board[i+6][j+6].type == BLACK && board[i+7][j+7].type == NONE){
                        if(i+7 >= 0 && i+7 <=7 && j+7 >= 0 && j+7 <=7){
                            row1[counter1] = i + 7;
                            col1[counter1] = j + 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        
        /* checking down-up diagonally */
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(board[i][j].type == WHITE){
                    if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == NONE){
                        if(i-2 >= 0 && i-2 <= 7 && j-2 >= 0 && j-2 <=7){
                            row1[counter1] = i - 2;
                            col1[counter1] = j - 2;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == BLACK && board[i-3][j-3].type == NONE){
                        if(i-3 >= 0 && i-3 <= 7 && j-3 >= 0 && j-3 <=7){
                            row1[counter1] = i - 3;
                            col1[counter1] = j - 3;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == BLACK && board[i-3][j-3].type == BLACK && board[i-4][j-4].type == NONE){
                        if(i-4 >= 0 && i-4 <= 7 && j-4 >= 0 && j-4 <=7){
                            row1[counter1] = i - 4;
                            col1[counter1] = j - 4;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == BLACK && board[i-3][j-3].type == BLACK && board[i-4][j-4].type == BLACK && board[i-5][j-5].type == NONE){
                        if(i-5 >= 0 && i-5 <= 7 && j-5 >= 0 && j-5 <=7){
                            row1[counter1] = i - 5;
                            col1[counter1] = j - 5;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == BLACK && board[i-3][j-3].type == BLACK && board[i-4][j-4].type == BLACK && board[i-5][j-5].type == BLACK && board[i-6][j-6].type == NONE){
                        if(i-6 >= 0 && i-6 <= 7 && j-6 >= 0 && j-6 <=7){
                            row1[counter1] = i - 6;
                            col1[counter1] = j - 6;
                            counter1++;
                        }
                    }
                    else if(board[i-1][j-1].type == BLACK && board[i-2][j-2].type == BLACK && board[i-3][j-3].type == BLACK && board[i-4][j-4].type == BLACK && board[i-5][j-5].type == BLACK && board[i-6][j-6].type == BLACK && board[i-7][j-7].type == NONE){
                        if(i-7 >= 0 && i-7 <= 7 && j-7 >= 0 && j-7 <=7){
                            row1[counter1] = i - 7;
                            col1[counter1] = j - 7;
                            counter1++;
                        }
                    }
                }
            }
        }
        return counter1;
    }
    else
    {
        return 0;
    }
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
