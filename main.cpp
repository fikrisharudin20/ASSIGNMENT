// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT1L 
// Names: AHMAD FIKRI BIN SHARUDIN | YUSRIENA AQIELAH BINTI MUHAMMAD NAFIZ HANS | NURHAZIRAH IZZATI BINTI ABD LATIF
// IDs: 1221302093 | 1221302876 | 1221302792 
// Emails: 1221302093@student.mmu.edu.my | 1221302876@student.mmu.edu.my | 1221302792@student.mmu.edu.my
// Phones: 0197581622 | 0183740376 | 0133330437
// ********************************************************* 

#include "pf/helper.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <random>
#include <conio.h>

using namespace std;

int x;
int y;
int a_x;
int a_y;


void title()                                      //Creating the title of the game 
{
    cout << "*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~*" << endl;
    cout << " *    | ALIEN VS ZOMBIES |     * " << endl;
    cout << "*~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~*" << endl;
    cout << "                                 " << endl;
    cout << "   >ELIMINATE ALL THE ZOMBIES<   " << endl;
    cout << "                                 " << endl;
}


void board()
{
    cout << "Hello aliens! set your rows and columns (odd numbers only)" << endl; 
    
    char again = 'Y';

    while (again == 'y' || again == 'Y')         //A while-loop to create the board 
    {
        cout << "Row => ";                       //Initializing the dimensions of the board set by user's input
        cin >> y;
        cout << "" << endl;

        cout << "Column => ";
        cin >> x;
        cout << "" << endl;

        if (x, y % 2 != 0)                       //Inside of while-loop there is an if else statement if the user inputs even numbers for the dimensions of the board
        {
            again = 'N';         
            a_x = x / 2;                        //When the board is created with set dimensions, put the Alien in the middle of the board
            a_y = y / 2;


            while (true)
            {

            for (int row = 0; row < y; row++)
            {

                cout << " ";
                for (int col = 0; col < x; col++)         //Top border of the board
                {
                    cout << "=-";                          
                }
                cout << "=" << endl;

                cout << setw(2) << (y - row);            // Y-coordinates of the side of the board with set width of 2



                for (int j = 0; j < x; ++j)
                {
                    string array[] = {"p", "h", "r", "<", ">", "^", "v", " ", " ", " ", " ", " ", " ", " ", " "};          //2d array for the objects in the board
                    int noOfObjects = 15;
                    

                    if (row == a_y && j == a_x)
                        cout << "|A";                   //Put alien in the middle of the board
                    
                    else
                        cout << "|" << " ";
                         
                }
                cout << "|" << endl;
            }

            cout << " ";
            for (int j = 0; j < x; ++j)                 //Bottom border of the board
            {
                cout << "=-";                           
            }
            cout << "=" << endl;

            cout << " ";                               //X-coordinates on the bottom of the board
            for (int j = 0; j < x; ++j)
            {
                int digit = (j + 1) / 10;             
                cout << " ";
                if (digit == 0)
                    cout << " ";
                else
                    cout << digit;
            }
            
            cout << endl;
            cout << " ";
            for (int j = 0; j < x; ++j)
            {
                cout << " " << (j + 1) % 10;
            }
           
            cout << endl;
            cout << endl
                 << endl;

                  char move;                                                                                  //Code for Alien movement
                  cout << "Enter your move (w = up, s = down, a = left, d = right, q = quit)"<< endl;
                  cin >> move;
                
                if (move == 'w'  && a_y > 0)
                    {
                        a_y--;
                    }
                 
        
                else if (move == 's' && a_y < y - 1)
                    {
                        a_y++;
                    }
                    
                else if (move == 'a' && a_x > 0)
                    {
                        a_x--;
                    }
                
                else if (move == 'd' && a_x < x - 1)
                    {
                        a_x++;
                    }
                    
                    
                else if (move == 'q')

                {
                  string confirm;                                       //If the user wants to quit the game
                  cout << "Are you sure? (yes or no) => ";
                  cin >> confirm;

                    if (confirm == "yes")
                    {

                       break; 
                       
                    }

                    else if ( confirm == "no")
                    {
                        
                    }

                    else 
                    {
                        cout << "Invalid input please enter yes or no" << endl;

                    }
    
                }
                
                else   
                    cout << "Invalid move. Please try again." << endl;
                    system("pause");


                

                system("cls"); 

            }
            
        }

        else    
            cout << "Young one, we only accept odd numbers!" << endl;                   //Display if user inputs even numbers for board dimensions
        cout << "" << endl;
        system("pause");
    }
    

}

int main()                                                                                                  
{
    
    title();

    board();
    
}