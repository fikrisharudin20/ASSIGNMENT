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
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

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
                  int x_coords = a_x + 1;
                  int y_coords = y - a_y;
                  cout << "Alien is now at (" << x_coords << ", " << y_coords << ")" << endl;  
                  cin >> move;
                  
                
                if (move == 'w'  && a_y > 0)
                    {
                        a_y--;
                        cout << "Alien moved up to (" << x_coords << ", " << y_coords + 1 << ")" << endl;
                    }
                 
        
                else if (move == 's' && a_y < y - 1)
                    {
                        a_y++;
                        cout << "Alien moved down to (" << x_coords << ", " << y_coords - 1 << ")" << endl;
                    }
                    
                else if (move == 'a' && a_x > 0)
                    {
                        a_x--;
                        cout << "Alien moved left to (" << x_coords - 1 << ", " << y_coords << ")" << endl;
                    }
                
                else if (move == 'd' && a_x < x - 1)
                    {
                        a_x++;
                        cout << "Alien moved right to (" << x_coords + 1 << ", " << y_coords << ")" << endl;
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

class GameObject
{
public:
    int x, y;
    char type;

    GameObject (int x_, int y_, char type_ ) : x(x_), y(y_), type(type_) {}
};

int main()
{
    // create game objects
    GameObject up_arrow (0,0, '^');
    GameObject down_arrow (1,0, 'v');
    GameObject left_arrow (2,0, '<');
    GameObject right_arrow (3,0, '>');
    GameObject health (4,0, 'h');
    GameObject pod (5, 0, 'p');
    GameObject rock (6, 0, 'r');
    GameObject empty (7, 0, ' ');
    GameObject trail (8, 0, '.');

    //print game objects
    std :: cout << "up_arrow: (" << up_arrow.x << "," << up_arrow.y << ") " << up_arrow.type << std :: endl;
    std::cout << "Down arrow: (" << down_arrow.x << "," << down_arrow.y << ") " << down_arrow.type << std::endl;
    std::cout << "Left arrow: (" << left_arrow.x << "," << left_arrow.y << ") " << left_arrow.type << std::endl;
    std::cout << "Right arrow: (" << right_arrow.x << "," << right_arrow.y << ") " << right_arrow.type << std::endl;
    std::cout << "Health: (" << health.x << "," << health.y << ") " << health.type << std::endl;
    std::cout << "Pod: (" << pod.x << "," << pod.y << ") " << pod.type << std::endl;
    std::cout << "Rock: (" << rock.x << "," << rock.y << ") " << rock.type << std::endl;
    std::cout << "Empty: (" << empty.x << "," << empty.y << ") " << empty.type << std::endl;
    std::cout << "Trail: (" << trail.x << "," << trail.y << ") " << trail.type << std::endl;

    return 0;
}

// Define a struct to hold game data
struct GameData {
    int score;
    string playerName;
    // Add any other necessary game data
};

// Function to save game data to a file
void saveGame(const GameData& gameData) {
    ofstream file("saved_game.txt");
    if (file.is_open()) {
        file << gameData.score << endl;
        file << gameData.playerName << endl;
        // Add any other necessary game data to file
        cout << "Game saved successfully." << endl;
    }
    else {
        cout << "Unable to save game." << endl;
    }
}

// Function to load game data from a file
GameData loadGame() {
    GameData gameData;
    ifstream file("saved_game.txt");
    if (file.is_open()) 
    {
        file >> gameData.score;
        file >> gameData.playerName;
        // Load any other necessary game data from file
        cout << "Game loaded successfully." << endl;
    }
    else 
    {
        cout << "Unable to load game." << endl;
    }
    return gameData;
}

int main() 
{
    // Initialize game data
    GameData gameData {0, "Player1"};
    
    // Play the game
    while (true) 
    {
        // Update game data as necessary
        // ...
        
        // Allow player to save or quit the game
        cout << "Enter 's' to save the game or 'q' to quit: ";
        char choice;
        cin >> choice;
        if (choice == 's') 
        {
            saveGame(gameData);
        }
        else if (choice == 'q') 
        {
            break;  // End game
        }
    }
    
    // Allow player to load saved game
    cout << "Do you want to load a saved game? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y') 
    {
        cout << "Loading game..." << endl;
        GameData loadedData = loadGame();
        // Use loadedData to resume game
        // ...
    }
    else 
    {
        cout << "Starting new game..." << endl;
        // Start a new game
        // ...
    }
    
    return 0;
}
