//Alex Oggerino
//project 6
//this is a program that plays a game of tic tac toe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 3
 
void array_of_arrays_ver(char arr[][COLS]); /* prototype */
void print_board(char arr[ROWS][COLS]); /*prints the board*/
void player_one_move(char arr[ROWS][COLS]);/*puts an '0' where specified by player 1*/
int check_stalemate(char arr[ROWS][COLS]);/*checks for full board*/
void computer_move(char arr[ROWS][COLS]);//puts in a computer move//
int check_legal(char arr[ROWS][COLS], int row, int col); // checks the validity of moves
int check_win(char arr[ROWS][COLS]); //this checks for 3 in a row


int main ()//this is the main function that chooses whose turn it is
{
    srand(time(NULL)); // this makes the random number functon work
    // declare 3x3 array
    printf("This program plays a game of tic-tac-toe\n");
    char matrix[ROWS][COLS] = {{'_','_', '_'},
                              {'_', '_', '_'},
                              {'_', '_', '_'}};
    int player = 2;
    char boardpiece = 'O';
    int check = 0;
    while(check_win(matrix) != 1  && check_stalemate(matrix) != 1)
        {  
            print_board(matrix);
            if(player % 2 == 0)
            {
                player_one_move(matrix);
            }
            else
            {
                computer_move(matrix);
            }
            player++;
            
        }
      print_board(matrix);   
}
void print_board(char arr[ROWS][COLS])//this function prints the board and what moves have been made by the player and the computer 
{
    printf("The current state of the game is: \n");
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void player_one_move(char arr[ROWS][COLS])//this function allows the user to enter their move
{
    int row, col;
        printf("Player 1 enter your selection [row,col]: ");
        scanf("%d%d", &row, &col);
        while (((row > 3 || row < 1) || (col > 3 || col < 1)) || (arr[row - 1][col - 1] != '_')) //this makes sure the value given is 1 to 3 AND the space isnt taken
        //this while loop is redundant with the check_legal function but i dont wann break anything
        {
            printf("Invalid move, Please enter a valid move!\n");
            scanf("%d%d", &row, &col);     
        }
        //printf("row = %d col = %d\n", row, col);//test print
        arr[row - 1][col - 1] = 'O';
        
}

void computer_move(char arr[ROWS][COLS])  //this function plays a random move for the computer
  // add these in? int* x, int* y
{
    int row, col;
    
                row = (int)( 3 * (double)rand() / (double) RAND_MAX);
                col = (int)( 3 * (double)rand() / (double) RAND_MAX);
                if(check_legal(arr, row, col) == 1)
                {
                    arr[row][col] = 'X';
                    printf("Player 2 had entered [row, col]: %d, %d \n", row + 1, col + 1);
                }
                else 
                {
                    computer_move(arr);
                }
}

int check_stalemate(char arr[ROWS][COLS])//this checks to see if the board is full
{
    int i, j;
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if ((arr[i][j]) == '_') 
                {
                    return 0;
                }
        }
    }
    printf ("Game over, no player wins.\n");
    return 1;
}
int check_legal(char arr[ROWS][COLS], int row, int col)//this makes sure the move made is legal
{
    if((arr[row][col]) == '_')
    {
        return 1;
    }
    return 0;
}


int check_win(char arr[ROWS][COLS]) //checks for tic tac toe!!!
{
    if ((arr [0][0] == arr [0][1]) && (arr [0][1] == arr [0][2]) && (arr [0][2] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][0] == arr [0][1]) && (arr [0][1] == arr [0][2]) && (arr [0][2] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
    if ((arr [1][0] == arr [1][1]) && (arr [1][1] == arr [1][2]) && (arr [1][2] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [1][0] == arr [1][1]) && (arr [1][1] == arr [1][2]) && (arr [1][2] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
    if ((arr [2][0] == arr [2][1]) && (arr [2][1] == arr [2][2]) && (arr [2][2] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [2][0] == arr [2][1]) && (arr [2][1] == arr [2][2]) && (arr [2][2] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
   if ((arr [0][0] == arr [1][0]) && (arr [1][0] == arr [2][0]) && (arr [2][0] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][0] == arr [1][0]) && (arr [1][0] == arr [2][0]) && (arr [2][0] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
  if ((arr [0][1] == arr [1][1]) && (arr [1][1] == arr [2][1]) && (arr [2][1] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][1] == arr [1][1]) && (arr [1][1] == arr [2][1]) && (arr [2][1] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
    if ((arr [0][2] == arr [1][2]) && (arr [1][2] == arr [2][2]) && (arr [2][2] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][2] == arr [1][2]) && (arr [1][2] == arr [2][2]) && (arr [2][2] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
    if ((arr [0][0] == arr [1][1]) && (arr [1][1] == arr [2][2]) && (arr [2][2] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][0] == arr [1][1]) && (arr [1][1] == arr [2][2]) && (arr [2][2] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }
    if ((arr [0][2] == arr [1][1]) && (arr [1][1] == arr [2][0]) && (arr [2][0] == 'X')) 
        {
        printf ("Congratulations, Player 2 wins!\n"); 
        return 1;
        }
    if ((arr [0][2] == arr [1][1]) && (arr [1][1] == arr [2][0]) && (arr [2][0] == 'O')) 
        {
        printf ("Congratulations, Player 1 wins!\n"); 
        return 1;
        }

return 0;
}
 

