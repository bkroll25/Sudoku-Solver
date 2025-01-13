#include "Sudoku.h"

//Braden Kroll
//1/13/25

/*
+ This program will actually do the "meat" of the project
+ actually creating and solving the Sudoku boards
*/

//Takes in a board and prints it out
void printBoard(Board sudoku){
    //Iterate over entire board:
    for(int x = 0; x < sudoku.length; x++){
        for(int y = 0; y < sudoku.squares[x].amount; y++){
            cout<<sudoku.squares[x].cells[y].value;
        }
        cout<<endl;
    }
}