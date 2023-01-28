// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT1L 
// Names: AHMAD FIKRI BIN SHARUDIN | MEMBER_NAME_2 | MEMBER_NAME_3 
// IDs: 1221302093 | MEMBER_ID_2 | MEMBER_ID_3 
// Emails: 1221302093@student.mmu.edu.my | MEMBER_EMAIL_2 | MEMBER_EMAIL_3 
// Phones: 0197581622 | MEMBER_PHONE_2 | MEMBER_PHONE_3 
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


void title()
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
    cout << "Hello young alien! set your rows and columns (odd numbers only)" << endl;
    
    char again = 'Y';

    while (again == 'y' || again == 'Y')
    {
        cout << "Row => ";
        cin >> y;
        cout << "" << endl;

        cout << "Column => ";
        cin >> x;
        cout << "" << endl;

        if (x, y % 2 != 0)
        {
            again = 'N';
            a_x = x / 2;
            a_y = y / 2;


            while (true)
            {

            for (int row = 0; row < y; row++)
            {

                cout << " ";
                for (int col = 0; col < x; col++)
                {
                    cout << "=-";
                }
                cout << "=" << endl;

                cout << setw(2) << (y - row);



                for (int j = 0; j < x; ++j)
                {
                    string array[] = {"p", "h", "r", "<", ">", "^", "v", " ", " ", " ", " ", " ", " ", " ", " "};
                    int noOfObjects = 15;
                    

                    if (row == a_y && j == a_x)
                        cout << "|A";
                    
                    else
                        cout << "|" << " ";
                         
                }
                cout << "|" << endl;
            }

            cout << " ";
            for (int j = 0; j < x; ++j)
            {
                cout << "=-";
            }
            cout << "=" << endl;

            cout << " ";
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

                  char move;
                  cout << "Enter your move (w = up, s = down, a = left, d = right, q = quit)"<< endl;
                  cin >> move;
                
                if (move == 'w' && a_y > 0)
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
                  string confirm;
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
            cout << "Young one, we only accept odd numbers!" << endl;
        cout << "" << endl;
        system("pause");
    }
    

}

int main()
{
    
    title();

    board();
    
}