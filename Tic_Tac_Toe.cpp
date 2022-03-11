#include<iostream>
#include<stdlib.h>

using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

  int row;
  int column;
  char sub = 'x';
  bool tie = false;
  string n1 = " " ;
  string n2 = " " ;

   
void function_1()
{
       

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

      else if (digit <1 || digit > 9)
      {
             cout<<"invalid input"<<endl;
      }

      if(sub == 'x' && board[row][column] != 'x' && board[row][column] != '0')
       {
         board[row][column] = 'x';
         sub ='0';
       }

       else if(sub == '0' && board[row][column] != 'x' && board[row][column] != '0') 
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
       {
              for(int i = 0; i < 3; i++)
              {
                     if(board[i][0] == board[i][1] && board[1][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
                     return true;
              }

              if(board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
              {
                     return true;
              }

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
           tie = true;
           return false;

       }
      
int main()
{

       
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