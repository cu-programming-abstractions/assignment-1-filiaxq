
#include "Fire.h"
#include "grid.h"
#include "vector.h"
#include "random.h"

using namespace std;

void updateFire(Grid<int>& fire) {
    int rows = fire.numRows();
    int cols = fire.numCols();


    Grid<int> newFire = fire;


    for (int row = rows - 2; row >= 0; row--) {
        for (int col = 0; col < cols; col++) {
            int value = fire[row + 1][col];


            int targetCol = col;
            int shift = randomInteger(-1, 1);
            if (col + shift >= 0 && col + shift < cols) {
                targetCol = col + shift;
            }


            if (randomChance(2.0 / 3) && value > 0) {
                value -= 1;
            }


            newFire[row][targetCol] = value;
        }
    }

    fire = newFire;
}
