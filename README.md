# Alien vs. Zombie

My group had developed the a simple C++ program that simulates a game called "Alien Vs Zombies".

![Alt text](https://imgtr.ee/images/2023/01/28/G57Ur.jpg "Title Screen")

The game starts by displaying the title of the game and then prompts the user to enter the number of rows and columns of the game board. The game board is displayed using a 
loop that iterates through each row and column, printing out the game board and the current position of the alien character represented by "A". The alien is also placed in the middle of the board according the to the user's preference of the board's dimension

![Alt text](https://imgtr.ee/images/2023/01/28/G5GTn.jpg "Prompting User for Dimensions")

The user will be playing as the alien and the controls are also prompted on the screen.

The goal of this game is to eliminate the all zombies on the board in order to win! Goodluck Aliens!

[Video Demo](https://www.youtube.com/watch?v=B2DL_4otjsA).

## Compilation Instructions

```
g++ main.cpp -o alienvszombie
```

## User Manual

After compiling the program, type in;

```
.\alienvszombie
```

The player will be prompted with the title screen and it will request two inputs for the user; row and columns which are y-dimensions and x-dimensions respectively.
*Note: it is way more suitable to play with dimensions where columns > rows* 

Eitherway, the user can set their own preferable dimensions for the board.

The "A" character is placed in the middle of the board and it can be moved with wasd keys which are up,left,down and right respectively.

The user can also put in a series of inputs such as "wwww" and it will move 4 times up.


## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

- Ahmad Fikri Bin Sharudin
- Yusriena Aqielah Binti Muhammad Nafiz Hans
- Nurhazirah Izzati Binti Abd Latif


