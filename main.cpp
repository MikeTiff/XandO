//Author: Michael Tiffany
#include <iostream>

using namespace std;

//GLOBAL CONSTANTS
const int ROWS = 3;
const int COLUMNS = 3;
const char BLANK = ' ';
const char X = 'X';
const char O = 'O';
const int QUIT = -1;

int main()
{
  //3x3 matrix of characters, initially with blank spaces in each position
  char board[ROWS][COLUMNS] = {{BLANK, BLANK, BLANK},
                               {BLANK, BLANK, BLANK},
                               {BLANK, BLANK, BLANK}};

  char turn = X, Winner = ' '; //Player X always goes first
  int row;
  int column;
  bool playing = true; //Continue playing by default

  do
   {
     cout<<turn<<"'s turn.\n";
     cout<<"Which column and row (0-2, or -1 for both to quit)?\n";
     cin>>column;
     cin>>row;

    //Make sure the user isn't quitting
     if(column == QUIT && row == QUIT)
      {
       playing = false;
      }
    //Print error if the column and/or row is out of bounds of 0-2
     else if( column < 0 || row < 0 || column > 2 || row > 2 )
      {
       cout<<"Values must be between 0 and 2.\n";
      }

     else
      { board[row][column] = turn;
       if (turn == 'X')
        {
         turn = O;
        }
       else
        {
         turn = X;
        }
      }  
    Winner = board[0][0]; 
    cout<<"\nBOARD\n-----\n";
    cout<<board[0][0]<<" "<<board[0][1]<<" "<<board[0][2]<<" "<<endl;
    cout<<board[1][0]<<" "<<board[1][1]<<" "<<board[1][2]<<" "<<endl;
    cout<<board[2][0]<<" "<<board[2][1]<<" "<<board[2][2]<<" "<<endl;
    if( ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[0][0] == board[1][0] && board[1][0] == board[2][0]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2])) && 
         board[0][0] != ' ')
       {
        Winner = board[0][0];
        playing = false;
  cout<<"Winner is "<<Winner<<endl;
       }

    if( ((board[0][2] == board[1][2] && board[1][2] == board[2][2]) ||
        (board[2][0] == board[2][1] && board[2][1] == board[2][2])) &&
         board[2][2] != ' ')
        {
         Winner = board[2][2];
         playing = false;
  cout<<"Winner is "<<Winner<<endl;
        }
 
    if( ((board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
        (board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) &&
         board[1][1] != ' ')
        {
         Winner = board[1][1];
         playing = false;

  cout<<"Winner is "<<Winner<<endl;
        }
   }
  while( playing == true );
  
  //cout<<"Winner is "<<Winner<<endl;
  cout<<"Goodbye!\n";
  
  return 0;
}
