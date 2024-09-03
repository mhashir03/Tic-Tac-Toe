#include <iostream> // cin, cout
#include <ctime> // time
using namespace std; // std::

void drawBoard(char *spaces); // declare function for drawing the tic tac toe board, accepts a pointer to a char array
void playerMove(char *spaces, char player); // declare function for handling the players moves, accepts a pointer to a char array and the players symbol
void computerMove(char *spaces, char player); // declare function for handling the computers moves, accepts a pointer to a char array and the computers symbol
bool checkWinner(char *spaces, char player, char computer); // declare function for checking if there is a winner, accepts a pointer to a char array and the symbols of the player and computer
bool checkTie(char *spaces); // declare function for checking if the game is a tie, accepts a pointer to a char array

int main() { // main function where the game starts

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // initialize an array of 9 chars representing the tic tac toe board with all spaces empty
    char player = 'X'; // sets player symbol as X
    char computer = 'O'; // sets computers symbol as O
    bool running = true; // bool var to control the game loop, initially set to true to keep game running

    drawBoard(spaces); // calls drawBoard function to display empty board 

        while(running) { // loop that runs as long as the game is running
            playerMove(spaces, player); // calls the playerMove function to handle players move
            drawBoard(spaces); // calls the drawBoard function to update the board after the players move
            if(checkWinner(spaces, player, computer)) { // checks to see if someone has won after players move
                running = false; // stops game if there is a winner
                break; // exits loop
            }
            else if(checkTie(spaces)) { // checks if the game is a tie after players move
                running = false; // stops game if there is a tie
                break; // exits loop
            }

            computerMove(spaces, computer); // calls the computerMove function to handle computers move
            drawBoard(spaces); // calls the drawBoard function to update board after computers move
            if(checkWinner(spaces, player, computer)) { // checks to see if someone has won after computers move
                running = false; // stops game if there is a winner
                break; // exits loop
            } 
            else if(checkTie(spaces)) { // checks if the game is a tie after computers move
                running = false; // stops game if there is a tie
                break; // exits loop
            }
        }
        cout << "Thanks for playing!\n"; // print after game ends 

    return 0;
}

void drawBoard(char *spaces) { // function to draw the tic tac toe board
    /*
    prints the current state of the board using the values in the spaces array
    */
    cout << "\n"; // for formatting
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
    cout << "\n"; // for formatting
}

void playerMove(char *spaces, char player) { // function to handle players move
    int number; // var to store the players chosen spot
    do {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number; // prompts player to enter a spot and stores the input in number
        number --; // decrements number by 1 to match array index 
        if(spaces[number] == ' ') { // checks if chosen spot is empty
            spaces[number] = player; // places players marker on chosen spot
            break; // exits loop after valid move
        }
    } while(number < 0 || number > 8); // repeats loop if player chooses invalid spot
}

void computerMove(char *spaces, char computer) { // function to handle computers move
    int number; // var to store the computers chosen spot
    srand(time(0)); // seeds the random number generator with the current time

    while(true) { 
        number = rand() % 9; // generates a random number between [0, 8]
        if(spaces[number] == ' ') { // checks if random chosen spot is empty
            spaces[number] = computer; // places computers marker on chosen spot
            break; // exits loop after valid move
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) { // function to check if there is a winner

    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) { // checks if first row has the same non-empty symbol
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) { // checks if second row has the same non-empty symbol
        spaces[3] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) { // checks if third row has the same non-empty symbol
        spaces[6] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) { // checks if first column has the same non-empty symbol
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) { // checks if second column has the same non-empty symbol
        spaces[1] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) { // checks if third column has the same non-empty symbol
        spaces[2] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) { // checks if first diagonal has the same non-empty symbol
        spaces[0] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) { // checks if second diagonal has the same non-empty symbol
        spaces[2] == player ? cout << "You Win!\n" : cout << "You Lose!\n";
    }   
    else{
        return false; // returns false if no winner
    }

    return true; // returns true if winner 
}

bool checkTie(char *spaces) { // function to check if there is a tie
    
    for(int i = 0; i < 9; i++) { // loops through each spot on the board
        if(spaces[i] == ' ') { // checks if there is any empty spot
            return false; // returns false if any spot is empty which means no tie
        }
    }
    cout << "It's a Tie!\n";
    return true; // returns true if all spots are filled and there is no winner meaning there is a tie
}