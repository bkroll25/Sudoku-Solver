#include "Sudoku.h"

//Braden Kroll
//1/13/25

/*
+ This program will actually do the "meat" of the project
+ actually creating and solving the Sudoku boards
*/

//Takes in a board and prints it out
void printBoard(Board sudoku){
    int subGridSize = sudoku.squares[0].length; //Subgrid size (e.g., 3 for standard Sudoku)
    int gridSize = sudoku.length;              //Full grid size (e.g., 9 for standard Sudoku)

    for(int row = 0; row < gridSize; row++){
        //Print a horizontal line between subgrids:
        if(row % subGridSize == 0 && row != 0){
            cout<<"------+-------+------"<<endl;
        }

        for(int col = 0; col < gridSize; col++){
            //Print a vertical line between subgrids:
            if(col % subGridSize == 0 && col != 0){
                cout<<"| ";
            }

            //Calculate which square and cell within the square this cell belongs to:
            int squareRow = row / subGridSize; //Row of the square
            int squareCol = col / subGridSize; //Column of the square
            int cellRow = row % subGridSize;   //Row within the square
            int cellCol = col % subGridSize;   //Column within the square

            //Get the index of the square and the cell:
            int squareIndex = squareRow * (gridSize / subGridSize) + squareCol;
            int cellIndex = cellRow * subGridSize + cellCol;

            //Print the cell value:
            cout<<sudoku.squares[squareIndex].cells[cellIndex].value<<" ";
        }
        cout<<endl;
    }
}

//Checks if a number is in a valid space
//Returns true if it is, false otherwise
bool Board::isValid(int row, int col, int num){
    return !inRow(row, num) && !inCol(col, num) && !inSquare(row, col, num);
}

//Checks if a number is in a row
//Returns true if it is, false otherwise
bool Board::inRow(int row, int num){
    int gridSize = sqrt(length);
    for(int col = 0; col < length; col++){
        int squareIndex = (row / gridSize) * gridSize + (col / gridSize);
        int cellIndex = (row % gridSize) * gridSize + (col % gridSize);
        if(squares[squareIndex].cells[cellIndex].value == num){
            return true;
        }
    }
    return false;
}

//Checks if a number is in a column
//Returns true if it is, false otherwise
bool Board::inCol(int col, int num){
    int gridSize = sqrt(length);
    for(int row = 0; row < length; ++row){
        int squareIndex = (row / gridSize) * gridSize + (col / gridSize);
        int cellIndex = (row % gridSize) * gridSize + (col % gridSize);
        if(squares[squareIndex].cells[cellIndex].value == num){
            return true;
        }
    }
    return false;
}


//Checks if a number is in a square
//Returns true if it is, false otherwise
bool Board::inSquare(int row, int col, int num){
    int gridSize = sqrt(length);
    int squareIndex = (row / gridSize) * gridSize + (col / gridSize);
    for(int i = 0; i < squares[squareIndex].amount; ++i){
        if(squares[squareIndex].cells[i].value == num){
            return true;
        }
    }
        return false;
}

bool Board::fillBoard(int row = 0, int col = 0){
    //Base case: if we have filled all rows
    if(row == length){ 
        return true;
    }

    random_device rd;
    mt19937 rng(rd());
    
    //Move to the next row if we've reached the end of the current row
    int nextRow = (col == length - 1) ? row + 1 : row;
    int nextCol = (col + 1) % length;

    //Randomized numbers 1 to length for variety
    vector<int> numbers(length);
    for(int i = 0; i < length; ++i){
        numbers[i] = i + 1;
    }
    
    shuffle(numbers.begin(), numbers.end(), rng);

    for(int num : numbers){
        if(isValid(row, col, num)){
            int gridSize = sqrt(length);
            int squareIndex = (row / gridSize) * gridSize + (col / gridSize);
            int cellIndex = (row % gridSize) * gridSize + (col % gridSize);
            squares[squareIndex].cells[cellIndex].value = num;
            
            //Recursively try to fill the rest of the board
            if(fillBoard(nextRow, nextCol))
                return true;

            //Undo assignment if it leads to no solution
            squares[squareIndex].cells[cellIndex].value = 0;
        }
    }
    return false; //Backtrack
}

void Board::generateFilledBoard(){
    fillBoard();
}