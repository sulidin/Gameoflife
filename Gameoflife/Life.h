/*
 * Life.h
 */
#include<iostream>
using namespace std;

const int maxrow = 20;
const int maxcol = 60;

class Life {
public:
    void initialize();
    void print();
    void update();

private:
    int grid[maxrow + 2][maxcol + 2];
    int neighbor_count(int row, int col);
};


void Life::initialize()
{
    int row, col, tot;
    for (row = 0; row <= maxrow + 1; row++)
        for (col = 0; col <= maxcol + 1; col++)
            grid[row][col] = 0;
    cout << "Please enter number of cells you would like to start\n";
    cin >> tot;
    cout << "List " << tot << " coordinates for living cells in 'x y' format.\n";

    cin >> row >> col;
    for (int i = 0; i < tot - 1 ; i++) {
        if (row > 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range.\n";
        else
            cout << "Row " << row << " is out range.\n";
        cin >> row >> col;
    }

}


void Life::print()
/*
 * Pre:     The Life object contains a configuration
 * Post:    The configuration is written for the user.
 *
 */
{
    int row, col;

    for (row = 1; row <= maxrow; row++) {
        for (col = 1; col <= maxcol; col++)
            if (grid[row][col] == 1) cout << "*";
            else cout << ' '; 
        cout << "\n";
    }
    cout << "\n";
}


void Life::update()
{
    int row, col;
    int new_grid[maxrow + 2][maxcol + 2];
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
            case 2:
                new_grid[row][col] = grid[row][col]; // Status stays the same
                break;
            case 3:
                new_grid[row][col] = 1; // cell is now alive
                break;
            default:
                new_grid[row][col] = 0; // cell is now dead
            }
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col < maxcol; col++)
            grid[row][col] = new_grid[row][col];
}

int Life::neighbor_count(int row, int col)
/*
 * Pre:     The life object contains a configuration, and the coordinates row and col
 *          define a cell inside a hedge.
 * Post:    The number of living neighbors of the specified cell is returned.
 *
 */
{
    int i, j;
    int count = 0;

    for (i = row - 1; i <= row + 1; i++)
        for (j = col - 1; j <= col + 1; j++)
            count += grid[i][j];
    count -= grid[row][col];
    return count;
}
