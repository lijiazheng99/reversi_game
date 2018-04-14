/*PLEASE DON'T DELETE*/
//This file is create and write by Jiazheng Li 16212162

/*Sub-Function for place the disk after user made the decision*/
void players_placement (enum colour defiened_colour, int row, int column, disk board[SIZE][SIZE]);

/*Sub-function for reversi after user place the disk*/
void Check_And_Reversi (enum colour defiened_colour, int row, int column, disk board[SIZE][SIZE]);

/*WARNING: THIS SUB-FUNCTION MUST! BE! USE! AFTER! REVERSI! FUNCTION!*/
/*Sub-function for renew points by count different color of disks*/
void Renew_Player_Points (player player1, player player2, disk board[SIZE][SIZE]);
//This file is create and written by Jiazheng Li 16212162
