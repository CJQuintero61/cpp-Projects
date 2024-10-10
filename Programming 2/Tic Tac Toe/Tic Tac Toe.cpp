//****************************************************************************************************
//This was my first attempt at making a Tic-Tac-Toe game in C++. The idea at first was simple then I decided
//I wanted to add some nice features like the play again option and loser goes first rule. Adding one thing
//led to the next, like with the play again option, well now I had to clear the board and reset flags and variables.
//Then for the draw checking system, I kept trying different things then just settled on making a new variable.
//Because of this, turn and counter are very similar but do different functions. Also, I'm pretty sure this could
//be heavily optimized but as for now, I'm going to be looking for new projects to work on. From this experience,
//I wanted to think of ways I could implement something and increase my problem-solving skills, while generally
//improving my coding skills too. The biggest thing I learned from this has to be the input validation.
//Before when I tried to validate integers, if a letter or symbol was entered the program would run
//an infinite loop. This new system works like a charm and is easy to remember and implement.
//Also, I got more used to passing a bunch of parameters into functions, using reference variables,
//strings, and the exit function.
//If I were to redesign this, I would want to make it more modular with more functions than the massive
//code dump into main, and to try to cut down on variables and other useless lines of code
//If it ain't broken, don't fix it, and it works perfectly in my tests, so I won't be changing it.
//Last updated: February 7, 2024
//****************************************************************************************************
#include <iostream>
#include <string>
using namespace std;

void getPlayerNames(string &, string &);
void showBoard(char []);
void checkWin(char [], int &, int &, bool &, bool &, bool &, bool &);
void showWin(string, string, int, int, bool &, bool &);
void playAgain(bool &);
void clearBoard(char [], int &, bool &, bool &);
void finalResults(string, string, int, int);

int main()
{
    string player1, player2;
    int score1 = 0, score2 = 0, turn = 0, counter = 0;
    char positions[10] = {'0','1','2','3','4','5','6','7','8','9' };
    char mark;
    int choice;
    bool taken = false, winner1 = false, winner2 = false, Again = false, loser1 = false, loser2 = false, draw = false;

    getPlayerNames(player1, player2);
    do
    {
        do
        {
            //The turn variable manages what players move it is and who goes first
            //The counter variable checks for draws. If it reaches 9, the loop breaks and a draw is printed out
            turn++;
            counter++;
            //Print the board and pass the positions array to show the marks
            showBoard(positions);

            //This will display after reiterating the do-while loop
            //It displays if a position is taken then sets the taken variable back to false
            //It then continues to re-ask the same player for another input
            if(taken)
            {
                cout << "This position is already taken.\n";
                taken = false;
            }
            //If the turn variable is odd, then it is player 1's turn and mark is set to X's
            if(!(turn % 2 == 0))
            {
                mark = 'X';
                cout << player1 << "'s Turn (X's).\n";
            }
                //If the turn variable is even, then it is player 2's turn and mark is set to O's
            else
            {
                mark = 'O';
                cout << player2 << "'s Turn (O's).\n";
            }
            //This asks for user input
            cout << "Please choose a position (1-9).\n";
            cin >> choice;

            //This while loop validates user input
            //It checks if the input is an integer and is between the range from 1-9
            while(!((cin) && (choice >= 1) && (choice <= 9)))
            {
                //Print out the invalid input message
                cout << "Invalid Input.\n";
                //Clear the invalid input
                cin.clear();
                //Discard the input
                cin.ignore(100, '\n');
                //Re-ask the question and get user input again
                cout << "Please choose a position (1-9).\n";
                cin >> choice;
            }

            //These are the cases for every spot 1-9 as well as the case for a spot already taken, and a default case
            //that should not be reachable, but will end the program if it is encountered somehow/
            //The positions array is set to the current players mark if the move is valid,
            //then after every mark, the win condition function is checked
            if(choice == 1 && positions[1] == '1')
            {
                positions[1] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 2 && positions[2] == '2')
            {
                positions[2] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 3 && positions[3] == '3')
            {
                positions[3] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 4 && positions[4] == '4')
            {
                positions[4] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 5 && positions[5] == '5')
            {
                positions[5] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 6 && positions[6] == '6')
            {
                positions[6] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 7 && positions[7] == '7')
            {
                positions[7] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 8 && positions[8] == '8')
            {
                positions[8] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(choice == 9 && positions[9] == '9')
            {
                positions[9] = mark;
                checkWin(positions, score1, score2, winner1, winner2, loser1, loser2);
            }
            else if(positions[choice] == 'X' || positions[choice] == 'O')
            {
                taken = true;
                //This is to decrement the turn counter to make sure the same player goes again
                //if their input was already taken
                turn--;
            }
            else
            {
                //By default, if this error occurs, end the program
                cout << "Error choosing a position. Ending the program.\n";
                exit(0);
            }
            //After turn 9 is done, break the loop due to a draw
            //It is important this checks for draws after the above cases check for a win
            if(counter == 9)
            {
                draw = true;
                break;
            }

        } //Continue this do-while loop until a win is detected
        while(!(winner1 || winner2));

        //Show the board and the winner
        showBoard(positions);
        //This only
        if(draw && !(winner1 || winner2))
        {
            //Print the Draw message and set the variable back to false
            draw = false;
            cout << "Draw!\n";
        }
        showWin(player1, player2, score1, score2, winner1, winner2);

        //Ask if players would like to replay
        playAgain(Again);
        if(Again)
        {
            //Reset the board
            clearBoard(positions, turn, loser1, loser2);
            //Reset counter back to 0. This checks for draws
            counter = 0;
        }

    }
    while(Again);

    finalResults(player1, player2, score1, score2);
    return 0;
}
void getPlayerNames(string &player1, string &player2)
{
    cout << "Enter player 1's name: \n";
    getline(cin, player1);
    cout << "Enter player 2's name: \n";
    getline(cin, player2);
}
void showBoard(char positions[])
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << positions[1] << "  |  " << positions[2] << "  |  " << positions[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << positions[4] << "  |  " << positions[5] << "  |  " << positions[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << positions[7] << "  |  " << positions[8] << "  |  " << positions[9] << endl;
    cout << "     |     |     " << endl;
}
void checkWin(char positions[], int &score1, int &score2, bool &winner1, bool &winner2, bool &loser1, bool &loser2)
{
    //Top left to bottom right diagonal
    if(positions[1] == 'X' && positions[5] == 'X' && positions[9] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[1] == 'O' && positions[5] == 'O' && positions[9] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Top right to bottom left diagonal
    else if(positions[3] == 'X' && positions[5] == 'X' && positions[7] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[3] == 'O' && positions[5] == 'O' && positions[7] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Top row
    else if(positions[1] == 'X' && positions[2] == 'X' && positions[3] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[1] == 'O' && positions[2] == 'O' && positions[3] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Middle row
    else if(positions[4] == 'X' && positions[5] == 'X' && positions[6] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[4] == 'O' && positions[5] == 'O' && positions[6] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Bottom row
    else if(positions[7] == 'X' && positions[8] == 'X' && positions[9] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[7] == 'O' && positions[8] == 'O' && positions[9] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Left column
    else if(positions[1] == 'X' && positions[4] == 'X' && positions[7] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[1] == 'O' && positions[4] == 'O' && positions[7] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Middle column
    else if(positions[2] == 'X' && positions[5] == 'X' && positions[8] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[2] == 'O' && positions[5] == 'O' && positions[8] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
    //Right column
    else if(positions[3] == 'X' && positions[6] == 'X' && positions[9] == 'X')
    {
        score1++;
        winner1 = true;
        loser2 = true;
    }
    else if(positions[3] == 'O' && positions[6] == 'O' && positions[9] == 'O')
    {
        score2++;
        winner2 = true;
        loser1 = true;
    }
}
void showWin(string player1, string player2, int score1, int score2, bool &winner1, bool &winner2)
{
    if(winner1)
    {
        cout << player1 << " wins!\n";
        winner1 = false;
    }
    else if(winner2)
    {
        cout << player2 << " wins!\n";
        winner2 = false;
    }
    cout << player1 << ": " << score1 << endl;
    cout << player2 << ": " << score2 << endl;
}
void playAgain(bool &Again)
{
    string choice;
    cout << "Would you like to play again (Yes/No)?\n";
    cin >> choice;

    while(!(cin && (choice == "Yes" || choice == "yes" || choice == "YES"
            || choice == "No" ||choice == "no" || choice == "NO")))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input.\n";
        cout << "Would you like to play again (Yes/No)?\n";
        cin >> choice;
    }
    if(choice == "Yes" || choice == "yes" || choice == "YES")
    {
        Again = true;
    }
    else if(choice == "No" || choice == "no" || choice == "NO")
    {
        Again = false;
    }
    else
    {
        //By default, if this error occurs, end the program
        cout << "Error from playing again. Ending the program.\n";
        exit(0);
    }
}
void clearBoard(char positions[], int &turn, bool &loser1, bool &loser2)
{
    //This resets each position
    positions[0] = '0';
    positions[1] = '1';
    positions[2] = '2';
    positions[3] = '3';
    positions[4] = '4';
    positions[5] = '5';
    positions[6] = '6';
    positions[7] = '7';
    positions[8] = '8';
    positions[9] = '9';

    //Loser goes first
    //If player 1 loses (meaning if loser1 is true) then turn resets to 0;
    if(loser1)
    {
        turn = 0;
        loser1 = false;
        loser2 = false;
    }
    //If player 2 loses (meaning loser2 is true) then turn gets reset to 1
    //to let player 2 go first in the next game
    else if(loser2)
    {
        turn = 1;
        loser1 = false;
        loser2 = false;
    }
    //If the first game is a draw, then player 2 will go first
    else if(!(loser1 && loser2))
    {
        turn = 1;
    }
    else
    {
        cout << "Error in Clear Board function. Ending the program.\n";
        exit(0);
    }

}
void finalResults(string player1, string player2, int score1, int score2)
{
    cout << endl;
    cout << endl;
    if(score1 > score2)
    {
        cout << player1 << " wins overall!\n";
    }
    else if(score2 > score1)
    {
        cout << player2 << " wins overall!\n";
    }
    else if(score1 == score2)
    {
        cout << "It's a draw overall!\n";
    }
    else
    {
        cout << "Error in the final results function. Ending the program\n";
        exit(0);
    }
    cout << player1 << ": " << score1 << endl;
    cout << player2 << ": " << score2 << endl;
    cout << endl;
    cout << "Thank you for playing!\n";
    cout << "This Tic-Tac-Toe game was made by Christian (CJ) Quintero on February 7, 2024.\n";
}




