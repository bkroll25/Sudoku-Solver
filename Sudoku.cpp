#include "Sudoku.h"

//Braden Kroll
//1/13/25

/*
+ This program will actually do the "meat" of the project
+ actually creating and solving the Sudoku boards
*/

//Takes in a board and prints it out
void printBoard(Board sudoku){
    int subGridSize = sudoku.squares[0].length; // Subgrid size (e.g., 3 for standard Sudoku)
    int gridSize = sudoku.length;              // Full grid size (e.g., 9 for standard Sudoku)

    for (int row = 0; row < gridSize; row++) {
        // Print a horizontal line between subgrids:
        if (row % subGridSize == 0 && row != 0) {
            cout << "------+-------+------" << endl;
        }

        for (int col = 0; col < gridSize; col++) {
            // Print a vertical line between subgrids:
            if (col % subGridSize == 0 && col != 0) {
                cout << "| ";
            }

            // Calculate which square and cell within the square this cell belongs to:
            int squareRow = row / subGridSize; // Row of the square
            int squareCol = col / subGridSize; // Column of the square
            int cellRow = row % subGridSize;   // Row within the square
            int cellCol = col % subGridSize;   // Column within the square

            // Get the index of the square and the cell:
            int squareIndex = squareRow * (gridSize / subGridSize) + squareCol;
            int cellIndex = cellRow * subGridSize + cellCol;

            // Print the cell value:
            cout << sudoku.squares[squareIndex].cells[cellIndex].value << " ";
        }
        cout << endl;
    }
}