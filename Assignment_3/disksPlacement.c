/*PLEASE DON'T DELETE*/
//This file is create and written by Jiazheng Li 16212162
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disksAndPlayers.h"
#include "disksPlacement.h"

//row:字母那行
//column:数字那行


void players_placement (enum colour defiened_colour, int row, int column, disk board[SIZE][SIZE])
{
    if (board[row][column].type==NONE)
    {
        board[row][column].pos.row=row;
        board[row][column].pos.col=column;
        board[row][column].type=defiened_colour;
        
        Check_And_Reversi (defiened_colour, row, column, board);
    }
}

/*My Idea is check the postition and reversi line by line.  */
/*Because when put a disk, it will just reversi the disks   */
/*between this disk and another disks on the line.          */
/*                                                          */
/*So I built a math model to deal with this problem.        */
/*                                                          */
/*               (Deriction) 0 (Column--)                   */
/*(Row-- && Column--)        ^           (Row++ && Column--)*/
/*           7               ^             1                */
/*               <           ^         >                    */
/*                   <       ^      >                       */
/*(Row--)                <   ^   >                  (Row++) */
/* |6|  <   <   <   <   <    O    >   >   >   >   >     2   */
/*                       <   v (New placed disk)            */
/*                   <       v      >                       */
/*               <           v         >                    */
/*           5               v             3                */
/*(Row-- && Column++)        v           (Row++ && Column++)*/
/*                           4 (Column++)                   */
/*                                                          */
//So I sepreate to 8 different satitution by deriction.
//
//Deriction 0: check by only column decrease                 (Column--)
//Deriction 1: check by row increase and column decrease     (Row++ && Column--)
//Deriction 2: check by only row increase                    (Row++)
//Deriction 3: check by row increase and column increase     (Row++ && Column++)
//Deriction 4: check by only column increase                 (Column++)
//Deriction 5: check by row decrease and column increase     (Row-- && Column++)
//Deriction 6: check by only row decrease                    (Row--)
//Deriction 7: check by row decrease and column decrease     (Row-- && Column--)
//
//For every driction, I will check from the third disk on the line (According to the rule, it ia meaningless to check the second postion, beacuse it's doesn't matter).
//Then it will check is it NONE first. If is NONE just break. Next check the postion one by one, until get the same color of the placed disk. If color of disks between placed disk and ckecked disk is not the same, counter will control loop go back and revese the disks color.
//Also there definately have some limitation. Row can't smaller than 0 and larger than 8, same as Column. Just to control it won't cause any werid error.

void Check_And_Reversi (enum colour defiened_colour, int row, int column, disk board[SIZE][SIZE])
{
    //Direction counter will check every direction
    for (int Direction_Counter=0 ; Direction_Counter<8 ; Direction_Counter++)
    {
        //orignal row and column saved by the "row" and "column"
        //"Row_check" and "Column_check" are based on data of row and column to doing decrease and increse operation to check every postion
        int Row_check = row;
        int Column_check = column;
        
        //Switch to defferent color
        switch (defiened_colour)
        {
            case WHITE:
                switch (Direction_Counter)
            {
                case 0:
                    Column_check -= 1;
                    while (Column_check > 0)
                    {
                        if (board[row][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[row][Column_check].type==WHITE)
                        {
                            if (board[row][Column_check+1].type==BLACK)
                            {
                                while (Column_check != column)
                                {
                                    board[row][Column_check].type=WHITE;
                                    Column_check++;
                                }
                            }
                        }
                        Column_check--;
                    }
                    break;
                case 1:
                    Column_check -= 1;
                    Row_check += 1;
                    while (Column_check > 0 && Row_check < 9)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==WHITE)
                        {
                            if (board[Row_check-1][Column_check+1].type==BLACK)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=WHITE;
                                    Column_check++;
                                    Row_check--;
                                }
                            }
                        }
                        Column_check--;
                        Row_check++;
                    }
                    break;
                case 2:
                    Row_check += 1;
                    while (Row_check < 9)
                    {
                        if (board[Row_check][column].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][column].type==WHITE)
                        {
                            if (board[Row_check-1][column].type==BLACK)
                            {
                                while (Row_check != row)
                                {
                                    board[Row_check][column].type=WHITE;
                                    Row_check--;
                                }
                            }
                        }
                        Row_check++;
                    }
                    break;
                case 3:
                    Column_check += 1;
                    Row_check += 1;
                    while (Column_check < 9 && Row_check < 9)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==WHITE)
                        {
                            if (board[Row_check-1][Column_check-1].type==BLACK)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=WHITE;
                                    Column_check--;
                                    Row_check--;
                                }
                            }
                        }
                        Column_check++;
                        Row_check++;
                    }
                    break;
                case 4:
                    Column_check += 1;
                    while (Column_check < 9)
                    {
                        if (board[row][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[row][Column_check].type==WHITE)
                        {
                            if (board[row][Column_check-1].type==BLACK)
                            {
                                while (Column_check != column)
                                {
                                    board[row][Column_check].type=WHITE;
                                    Column_check--;
                                }
                            }
                        }
                        Column_check++;
                    }
                    break;
                case 5:
                    Column_check += 1;
                    Row_check -= 1;
                    while (Column_check < 9 && Row_check > 0)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==WHITE)
                        {
                            if (board[Row_check+1][Column_check-1].type==BLACK)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=WHITE;
                                    Column_check--;
                                    Row_check++;
                                }
                            }
                        }
                        Column_check++;
                        Row_check--;
                    }
                    break;
                case 6:
                    Row_check -= 1;
                    while (Row_check > 0)
                    {
                        if (board[Row_check][column].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][column].type==WHITE)
                        {
                            if (board[Row_check+1][column].type==BLACK)
                            {
                                while (Row_check != row)
                                {
                                    board[Row_check][column].type=WHITE;
                                    Row_check++;
                                }
                            }
                        }
                        Row_check--;
                    }
                    break;
                case 7:
                    Column_check -= 1;
                    Row_check -= 1;
                    while (Column_check > 0 && Row_check > 0)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==WHITE)
                        {
                            if (board[Row_check+1][Column_check+1].type==BLACK)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=WHITE;
                                    Column_check++;
                                    Row_check++;
                                }
                            }
                        }
                        Column_check--;
                        Row_check--;
                    }
                    break;
            }
                break;
                
            case BLACK:
                switch (Direction_Counter)
            {
                case 0:
                    Column_check -= 1;
                    while (Column_check > 0)
                    {
                        if (board[row][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[row][Column_check].type==BLACK)
                        {
                            if (board[row][Column_check+1].type==WHITE)
                            {
                                while (Column_check != column)
                                {
                                    board[row][Column_check].type=BLACK;
                                    Column_check++;
                                }
                            }
                        }
                        Column_check--;
                    }
                    break;
                case 1:
                    Column_check -= 1;
                    Row_check += 1;
                    while (Column_check > 0 && Row_check < 9)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==BLACK)
                        {
                            if (board[Row_check-1][Column_check+1].type==WHITE)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=BLACK;
                                    Column_check++;
                                    Row_check--;
                                }
                            }
                        }
                        Column_check--;
                        Row_check++;
                    }
                    break;
                case 2:
                    Row_check += 1;
                    while (Row_check < 9)
                    {
                        if (board[Row_check][column].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][column].type==BLACK)
                        {
                            if (board[Row_check-1][column].type==WHITE)
                            {
                                while (Row_check != row)
                                {
                                    board[Row_check][column].type=BLACK;
                                    Row_check--;
                                }
                            }
                        }
                        Row_check++;
                    }
                    break;
                case 3:
                    Column_check += 1;
                    Row_check += 1;
                    while (Column_check < 9 && Row_check < 9)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==BLACK)
                        {
                            if (board[Row_check-1][Column_check-1].type==WHITE)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=BLACK;
                                    Column_check--;
                                    Row_check--;
                                }
                            }
                        }
                        Column_check++;
                        Row_check++;
                    }
                    break;
                case 4:
                    Column_check += 1;
                    while (Column_check < 9)
                    {
                        if (board[row][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[row][Column_check].type==BLACK)
                        {
                            if (board[row][Column_check-1].type==WHITE)
                            {
                                while (Column_check != column)
                                {
                                    board[row][Column_check].type=BLACK;
                                    Column_check--;
                                }
                            }
                        }
                        Column_check++;
                    }
                    break;
                case 5:
                    Column_check += 1;
                    Row_check -= 1;
                    while (Column_check < 9 && Row_check > 0)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==BLACK)
                        {
                            if (board[Row_check+1][Column_check-1].type==WHITE)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=BLACK;
                                    Column_check--;
                                    Row_check++;
                                }
                            }
                        }
                        Column_check++;
                        Row_check--;
                    }
                    break;
                case 6:
                    Row_check -= 1;
                    while (Row_check > 0)
                    {
                        if (board[Row_check][column].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][column].type==BLACK)
                        {
                            if (board[Row_check+1][column].type==WHITE)
                            {
                                while (Row_check != row)
                                {
                                    board[Row_check][column].type=BLACK;
                                    Row_check++;
                                }
                            }
                        }
                        Row_check--;
                    }
                    break;
                case 7:
                    Column_check -= 1;
                    Row_check -= 1;
                    while (Column_check > 0 && Row_check > 0)
                    {
                        if (board[Row_check][Column_check].type==NONE)
                        {
                            break;
                        }
                        if (board[Row_check][Column_check].type==BLACK)
                        {
                            if (board[Row_check+1][Column_check+1].type==WHITE)
                            {
                                while (Column_check != column && Row_check != row)
                                {
                                    board[Row_check][Column_check].type=BLACK;
                                    Column_check++;
                                    Row_check++;
                                }
                            }
                        }
                        Column_check--;
                        Row_check--;
                    }
                    break;
            }
                break;
        }
    }
}
//This file is create and written by Jiazheng Li 16212162
