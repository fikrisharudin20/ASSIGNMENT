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
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include <iomanip>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;


// Define a struct to hold game data
struct GameData
{
    int score;
    string playerName;
    
};

struct Zombie {
    int x;
    int y;
    int health;
};


// Function to save game data to a file
void saveGame(const GameData &gameData)
{
    ofstream file("saved_game.txt");
    if (file.is_open())
    {
        file << gameData.score << endl;
        file << gameData.playerName << endl;
        // Add any other necessary game data to file
        cout << "Game saved successfully." << endl;
    }
    else
    {
        cout << "Unable to save game." << endl;
    }
}

// Function to load game data from a file
GameData loadGame()
{
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

void save()
{
    // Initialize game data
    GameData gameData{0, "Player1"};

    // Play the game
    while (true)
    {
        // Update game data as necessary

        // Allow player to save or quit the game
        cout << "Enter 's' to start and record your profile or 'q' to load existing save file: ";
        char choice;
        cin >> choice;
        if (choice == 's')
        {
            saveGame(gameData);
            false;
        }
        else if (choice == 'q')
        {
            break; // End game
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
        
    }
    else
    {
        cout << "Starting new game..." << endl;
        // Start a new game
        
    }
}

int x = 9;
int y = 5;
int a_x;
int a_y;
int alien_health = 100;
int alien_damage = 0;
int zombie_count = 1;
int z,z_loc1,z_loc2;
int zombie_life[9],zombie_attack[9],zombie_range[9];

void title() // Creating the title of the game
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
    char option;
    cout<<"Default Board Settings:"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"Board Rows     :"<<y<<endl;
    cout<<"Board Columns  :"<<x<<endl;
    cout<<"Zombie Count   :"<<zombie_count<<endl;
    cout<<"Do you wish to change the game settings (y/n)? =>";
    cin>>option;
   
    z_loc1 = rand() % y ;
    z_loc2 = rand() % x -2;
    char again = 'Y';

    

    

    while (again == 'y' || again == 'Y') // A while-loop to create the board
    {
       if(option == 'Y' || option == 'y')
       {
        
        cout << "Hello aliens! set your rows and columns (odd numbers only)" << endl;
        cout << "Row => "; // Initializing the dimensions of the board set by user's input
        cin >> y;
        cout << "" << endl;

        cout << "Column => ";
        cin >> x;
        cout << "" << endl;
        cout << "Enter the number of zombies => ";
        cin >> zombie_count;
        cout << "" << endl;
       }
        for(int i = 0;i<zombie_count;i++)
            {
                zombie_life[i] = rand() %100 + 1;
                zombie_attack[i] = rand() %100 + 1;
                zombie_range[i] = rand() %5 +1;
            }
        

        if (x, y % 2 != 0 && zombie_count >= 1 && zombie_count <=9 ) // Inside of while-loop there is an if else statement if the user inputs even numbers for the dimensions of the board
        {
            again = 'N';
            a_x = x / 2; // When the board is created with set dimensions, put the Alien in the middle of the board
            a_y = y / 2;
            z = 1;

            vector<string> objects = {"p", "h", "r", "<", ">", "^", "v", "h", "r", " ", " ", " ", " ", " ", " "};
            shuffle(objects.begin(), objects.end(), default_random_engine(time(NULL))); // shuffle the objects

            // Create a 2D array to store the objects

            string **boardObjects = new string *[y];
            for (int i = 0; i < y; i++)
            {
                boardObjects[i] = new string[x];
            }
            

            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    if (i == a_y && j == a_x) 
                    {
                        boardObjects[i][j] = "A"; // Put alien in the middle of the board
                    }

                    
                    else
                    {
                        boardObjects[i][j] = objects[(i * x + j) % objects.size()]; // get the object at a specific index in the shuffled objects vector
                    }
                    
                    

                }
            }

            

            while (true)
            {

                for (int row = 0; row < y; row++)
                {

                    cout << " ";
                    for (int col = 0; col < x; col++) // Top border of the board
                    {
                        cout << "=-";
                    }
                    cout << "=" << endl;

                    cout << setw(2) << (y - row); // Y-coordinates of the side of the board with set width of 2

                    for (int j = 0; j < x; ++j)
                    {

                        

                        if (row == z_loc1 && j ==z_loc2 && z <= zombie_count)
                        {
                            cout << "|"<< z;
                            z_loc1 = row + 1;
                            z_loc2 --;
                            z++;
                            
                        }


                      else
                        cout << "|" << boardObjects[row][j];

                        
                    }
                    cout << "|" << endl;
                }

                cout << " ";
                for (int j = 0; j < x; ++j) // Bottom border of the board
                {
                    cout << "=-";
                }
                cout << "=" << endl;

                cout << " "; // X-coordinates on the bottom of the board
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

                // Code for Alien movement and for board objects

                int alien_new_health = alien_health;
                cout << "|| "
                     << "Alien Health (" << alien_new_health << ")"
                     << "  ||"
                     << "  "
                     << "Alien Damage (" << alien_damage << ")"
                     << " || " << endl;
                for(int i = 0;i<zombie_count;i++)
                    {
                        cout<<"|| Zombie "<<i+1 <<": Life "<<zombie_life[i]<<", Attack  "<<zombie_attack[i]<<", Range "<<zombie_range[i] << "||" << endl;
                    }

                char move;
                cout << "|| Enter your move (w = up, s = down, a = left, d = right, q = quit) ||" << endl;
                cout << " " << endl;
                int x_coords = a_x + 1;
                int y_coords = y - a_y;
                cout << "|| Alien is now at (" << x_coords << ", " << y_coords << ") ||" << endl;
                cin >> move;

                if (move == 'w' && a_y > 0)
                {
                    // Check for arrow
                    if (boardObjects[a_y - 1][a_x] == ">")
                    {
                        move = 'd'; // Change direction to right
                    }
                    else if (boardObjects[a_y - 1][a_x] == "<")
                    {
                        move = 'a'; // Change direction to left
                    }
                    else if (boardObjects[a_y - 1][a_x] == "v")
                    {
                        move = 's'; // Change direction to down
                    }

                    cout << "Moving Up!" << endl;

                    for (int w = 0; a_y > 0; ++w)
                    {

                        if (boardObjects[a_y - 1][a_x] != "r") // check if the next position is a rock
                        {
                            if (boardObjects[a_y - 1][a_x] == "h") // check if the next position is a health object
                            {
                                if (alien_health < 100)
                                {
                                    alien_health += 20; // increase alien health by 20
                                    int alien_new_health = alien_health;
                                    cout << "Alien gained 20 health points!" << endl;
                                }
                            }
                            // move Alien up
                            boardObjects[a_y][a_x] = " "; // clear current position
                            a_y--;
                            boardObjects[a_y][a_x] = "A"; // update new position
                        }

                        else // stop moving if the next position is a rock
                        {
                            cout << "Ouchies! You hit a rock" << endl;
                            break;
                        }
                    }
                }

                else if (move == 's' && a_y < y - 1)
                {
                    // Check for arrow
                    if (boardObjects[a_y + 1][a_x] == ">")
                    {
                        move = 'd'; // Change direction to right
                    }
                    else if (boardObjects[a_y + 1][a_x] == "<")
                    {
                        move = 'a'; // Change direction to left
                    }
                    else if (boardObjects[a_y + 1][a_x] == "^")
                    {
                        move = 'w'; // Change direction to up
                    }

                    cout << "Down We Go!" << endl;

                    for (int s = 0; a_y < y - 1; ++s)
                    {
                        if (boardObjects[a_y + 1][a_x] != "r") // check if the next position is a rock
                        {
                            if (boardObjects[a_y + 1][a_x] == "h") // check if the next position is a health object
                            {
                                if (alien_health < 100)
                                {
                                    alien_health += 20; // increase alien health by 20
                                    int alien_new_health = alien_health;
                                    cout << "Alien gained 20 health points!" << endl;
                                }
                            }

                            boardObjects[a_y][a_x] = " "; // clear current position
                            a_y++;
                            boardObjects[a_y][a_x] = "A"; // update new position
                        }
                        else // stop moving if the next position is a rock
                        {
                            cout << "Ouchies! You hit a rock" << endl;
                            break;
                        }
                    }
                }

                else if (move == 'a' && a_x > 0)
                {
                    // Check for arrow
                    if (boardObjects[a_y][a_x - 1] == "v")
                    {
                        move = 's'; // Change direction to down
                    }
                    else if (boardObjects[a_y][a_x - 1] == "^")
                    {
                        move = 'w'; // Change direction to up
                    }
                    else if (boardObjects[a_y][a_x - 1] == ">")
                    {
                        move = 'd'; // Change direction to right
                    }
                    cout << "Aye, aye! Left, Captain" << endl;

                    for (int a = 0; a_x > 0; ++a)
                    {
                        if (boardObjects[a_y][a_x - 1] != "r") // check if the next position is a rock
                        {
                            if (boardObjects[a_y][a_x - 1] == "h") // check if the next position is a health object
                            {
                                if (alien_health < 100)
                                {
                                    alien_health += 20; // increase alien health by 20
                                    int alien_new_health = alien_health;
                                    cout << "Alien gained 20 health points!" << endl;
                                }
                            }

                            boardObjects[a_y][a_x] = " "; // clear current position
                            a_x--;
                            boardObjects[a_y][a_x] = "A"; // update new position
                        }
                        else // stop moving if the next position is a rock
                        {
                            cout << "Ouchies! You hit a rock" << endl;
                            break;
                        }
                    }
                }

                else if (move == 'd' && a_x < x - 1)
                {
                    // Check for arrow
                    if (boardObjects[a_y][a_x + 1] == "v")
                    {
                        move = 's'; // Change direction to down
                    }
                    else if (boardObjects[a_y][a_x + 1] == "^")
                    {
                        move = 'w'; // Change direction to up
                    }
                    else if (boardObjects[a_y][a_x + 1] == "<")
                    {
                        move = 'a'; // Change direction to left
                    }

                    cout << "Go Right, Cuz You're Right!" << endl;

                    for (int d = 0; a_x < x - 1; ++d)
                    {
                        if (boardObjects[a_y][a_x + 1] != "r") // check if the next position is a rock
                        {
                            if (boardObjects[a_y][a_x + 1] == "h")
                            {
                                if (alien_health < 100)
                                {
                                    alien_health += 20; // increase alien health by 20
                                    int alien_new_health = alien_health;
                                    cout << "Alien gained 20 health points!" << endl;
                                }
                            }

                            boardObjects[a_y][a_x] = " "; // clear current position
                            a_x++;
                            boardObjects[a_y][a_x] = "A"; // update new position
                        }
                        else // stop moving if the next position is a rock
                        {
                            cout << "Ouchies! You hit a rock" << endl;
                            break;
                        }
                    }
                }

                else if (move == 'q')

                {
                    string confirm; // If the user wants to quit the game
                    cout << "Are you sure? (yes or no) => ";
                    cin >> confirm;

                    if (confirm == "yes")
                    {

                        break;
                    }

                    else if (confirm == "no")
                    {
                    }

                    else
                    {
                        cout << "Invalid input please enter yes or no" << endl;
                    }
                }

                else
                    cout << "Invalid move. A warrior never leaves!" << endl;
                system("pause");

                system("cls");
            }
        }

        else
            cout << "Young one, we only accept odd numbers!" << endl; // Display if user inputs even numbers for board dimensions
        cout << "" << endl;
        system("pause");
    }
}

int main()
{

    save();
    srand(time(NULL));
    title();
    board();

    return 0;
}
