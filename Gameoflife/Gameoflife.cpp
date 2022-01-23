// Gameoflife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

using namespace std;

#include "Life.h"

// Function Prototypes -
void instructions();
bool user_says_yes();
int main()
{
    /*
     * Pre:     The user supplies an initial configuration of living cells
     * Post:    The program prints a sequence of pictures showing the changes in the configuration of
     *          living cells according to the rules for the game of Life.
     * Uses:    The class life and its methods initialize(), print(), and update(), The functions
     * instructions(), user_says_yes()
     */
    Life configuration;
    instructions();
    configuration.initialize();
    //configuration.print();
    //cout << "Continue viewing new generations? \n";
    //while (user_says_yes()) {
    int n = 0;
    while (n<20) {
        configuration.update();
        configuration.print();
        n++;
        if (n ==19 ) {
            if (user_says_yes()) {
                n = 0;
            }
        }
        Sleep(500);
    }
    

}


#include <iostream>
using namespace std;

void instructions() {
    /*
     * Pre:     None
     * Post:    Instructions for using the Life program have been printed.
     *
     */
    cout << "Welcome to Conway's game of Life.\n";
    cout << "This game uses a grid of size " << maxrow << "by " << maxcol << " in which\n";
    cout << "each cell can either be occupied by an organism or not.\n";
    cout << "The occupied cells change from generation to generation \n";
    cout << "according to the number of neighboring cells which are alive.\n";
    //RULES OF THE GAME
    cout << "Rules" << endl;
    cout << "1. An individual cell survives if there are 2 or 3 neighbours" << endl;
    cout << "2. An individual cell dies if it has more than 3 or less than 2 neighbours" << endl;
    cout << "3. An individual cell borns into each empty square with exactly 3 cells as neighbors." << endl;
  
}

#include <iostream>
using namespace std;

bool user_says_yes() {
    int c;
    bool initial_response = true;
    do {
        if (initial_response)
            cout << "Would you like to continue viewing new generations ? (y,n)?" << flush;
        else
            cout << "Respond with either y or n:" << flush;
        do {
            c = cin.get();
        } while (c == '\n' || c == ' ' || c == '\t');
        initial_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');

}
