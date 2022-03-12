#include<iostream>
#include<stdlib.h>

using namespace std;
//declaring the array
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 

  int row;
  int column;
  char sub = 'x';
  bool tie = false;
  string n1 = " " ;
  string n2 = " " ;

   
void function_1()
{
   //this function is for the display of the structure of the board to play the game     

       cout<<"   |     |  \n";
       cout<<" "<<board[0][0]<<" |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";      
       cout<<"___|_____|___  \n";        
       cout<<"   |     |  \n";       
       cout<<" "<<board[1][0]<<" |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n"; 
       cout<<"___|_____|___  \n";
       cout<<"   |     |  \n";  
       cout<<" "<<board[2][0]<<" |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";      
       cout<<"   |     |  \n";
    
}

void function_2()
{
  // this function is used to identify the space where the player wants to put the value and play his turn and the if statements are used to find that space in the structure
      int digit;
      
      if(sub == 'x')
      {
          cout<<n1<<" please enter";
          cin>>digit;
      }

      if(sub == '0')
      {
          cout<<n2<<" please enter";
          cin>>digit;
      }
     
      if(digit == 1 )
      {
             row    = 0;
             column = 0;
      } 

       if(digit == 2 )
      {
             row    = 0;
             column = 1;
      } 

       if(digit == 3 )
      {
             row    = 0;
             column = 2;
      } 
     
        if(digit == 4 )
      {
             row    = 1;
             column = 0;
      } 

       if(digit == 5 )
      {
             row    = 1;
             column = 1;
      } 

       if(digit == 6 )
      {
             row    = 1;
             column = 2;
      } 

       if(digit == 7 )
      {
             row    = 2;
             column = 0;
      } 

       if(digit == 8)
      {
             row    = 2;
             column = 1;
      } 

       if(digit == 9 )
      {
             row    = 2;
             column = 2;
      } 

      else if (digit <1 || digit > 9)   // if any other box is entered other than between 1-9 , then it is a invalid input
      {
             cout<<"invalid input"<<endl;
      }

      if(sub == 'x' && board[row][column] != 'x' && board[row][column] != '0')  //this is to check if there is any empty spaces left in the structure if there is any it updates for player 1
       {
         board[row][column] = 'x';
         sub ='0';
       }

       else if(sub == '0' && board[row][column] != 'x' && board[row][column] != '0')   //this is to check if there is any empty spaces left in the structure if there is any it updates for player 2
       {
          board[row][column] = '0';
          sub ='x';
       }
       else{
              cout<<"there is no empty space"<<endl; 
              function_2();
       }
       function_1();
}
   
        bool function_3()
       {     // this function check if there is any winning line in the structure that is vertical or horizontal
              for(int i = 0; i < 3; i++)
              {
                     if(board[i][0] == board[i][1] && board[1][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
                     return true;
              }

              if(board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
              {
                     return true;
              }
      //this is to check if the spaces are fully completed or game is finished
         for(int i = 0; i <3; i++)
         {
                for(int j = 0; j<3; j++)
                {
                       if(board[i][j] != 'x' && board[i][j] != '0')
                       {
                             return false;
                       }
                }
         }
           tie = true;  //this is a tie situation
           return false;

       }
      
int main()
{
//input and output function to display and enter the value
       cout<<"ttt T I C --T A C --T O Ettt";
       cout<<"Enter thr name of first player: \n";
       getline(cin, n1);

       cout<<"Enter the name of second player: \n";
       getline(cin, n2);
       
       cout<<n1<<" is player so he/she will play first \n";
       cout<<n2<<" is player so he/she will play second \n";


       while(!function_3())
       {
            function_1();
            function_2();
            function_3();
      }
      // condition to check who wins the game
      if(sub == 'x' && tie == false)
      {
             cout<<n1<<"WINS THE GAME"<<endl;
      }
      else if(sub == '0' && tie == false)
      {
             cout<<n2<<"WINS THE GAME"<<endl;
             
      }
      else{
             cout<<"its a draw"<<endl;
      }
}
