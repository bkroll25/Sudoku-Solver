#include <iostream>
#include <random>
#include "Sudoku.h"

using namespace std;

//Braden Kroll
//1/13/2025
/*
+ This program is the menu system that is used to run the algorithms that create and solve the sudoku boards
*/

//Prototypes:
Board sudokuSolver(Board puzzle);

void menu(){
    char userInput;
    while(true){
        //Text blurb:
        cout<<"Sudoku Solver"<<endl;
        cout<<"Select one of the following"<<endl;
        cout<<"[1] Create a 9x9 puzzle"<<endl;
        cout<<"[2] Create a 9x9 puzzle with variable blanks"<<endl;
        cout<<"[3] Create a nxn size puzzle"<<endl;
        cout<<"[q] Quit"<<endl<<endl;

        //Take in input
        cout<<"Input: ";
        cin>>userInput;
        cout<<endl;

        //Actual Menu:
        if(userInput == '1'){
            //9x9 Sudoku Board
            Board sudoku;
            sudoku.generatePuzzle(42);

            cout<<"Solution:"<<endl;
            printBoard(sudoku.solution, sudoku.length);
            cout<<endl;
            cout<<"Puzzle:"<<endl;
            printBoard(sudoku.puzzle, sudoku.length);
            cout<<endl<<endl<<endl;

            cout<<"Starting Sudoku Solver:"<<endl;
            sudoku = sudokuSolver(sudoku);
            printBoard(sudoku.puzzle, sudoku.length);


        }else if(userInput == '2'){
            //Variable blanks Sudoku Board
            Board sudoku;
            int blanks;
            
            cout<<"How many Blanks?"<<endl;
            cout<<"(Note must be from 1-81, and anything above 49 is not guaranteed to have only 1 solution)"<<endl;
            cout<<"Input: ";
            cin>>blanks;
            sudoku.generatePuzzle(blanks);

            cout<<"Solution:"<<endl;
            printBoard(sudoku.solution, sudoku.length);
            cout<<endl;
            cout<<"Puzzle:"<<endl;
            printBoard(sudoku.puzzle, sudoku.length);
            cout<<endl<<endl<<endl;

            cout<<"Starting Sudoku Solver:"<<endl;
            sudoku = sudokuSolver(sudoku);
            printBoard(sudoku.puzzle, sudoku.length);

        }else if(userInput == '3'){
            //nxn Sudoku Board
            int length = 0;

            cout<<"What size Sudoku board do you want?"<<endl;
            cout<<"(Note: size refers to the length of the board, a noraml board is 9x9)"<<endl;
            cout<<"The size must be a perfect square, otherwise the code will not work"<<endl;
            cout<<"Ex: 4, 9, 16, 25, 36, 49, 64, etc."<<endl<<endl;
            cout<<"Input: ";
            
            cin>>length;

            Board sudoku(length);
            printBoard(sudoku.solution, sudoku.length);
            cout<<endl;

            cout<<"Starting Sudoku Solver:"<<endl;
            sudoku = sudokuSolver(sudoku);
            printBoard(sudoku.puzzle, sudoku.length);

            
        }else if(userInput == 'q' || userInput == 'Q'){
            //Quit
            break;
        }else{
            //Incorrect input
            cout<<"Incorrect input, please try again"<<endl<<endl;
        }
    }
}

//Remove possibilities from a single cell using it's row, col and square values
void eliminate(vector<vector<int>>& possible, Board& puzzle, int squareIndex, int cellIndex) {
    int gridSize = sqrt(puzzle.length);
    int row = (squareIndex / gridSize) * gridSize + (cellIndex / gridSize);
    int col = (squareIndex % gridSize) * gridSize + (cellIndex % gridSize);

    // Filter out invalid numbers
    auto& cellPossibilities = possible[squareIndex * gridSize + cellIndex];
    cellPossibilities.erase(
        std::remove_if(
            cellPossibilities.begin(),
            cellPossibilities.end(),
            [&puzzle, row, col](int num) {
                return !puzzle.isValid(row, col, num);
            }
        ),
        cellPossibilities.end()
    );
}

//This will actually solve the puzzles
Board sudokuSolver(Board puzzle){
    vector<vector<int>> possible(81, vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9});
    int gridSize = sqrt(puzzle.length);
    int iter = 0;
    
    while(puzzle.puzzle != puzzle.solution){
        for(int squareIndex = 0; squareIndex < puzzle.length; squareIndex++) {
            for(int cellIndex = 0; cellIndex < puzzle.puzzle[squareIndex].amount; cellIndex++){
                if(puzzle.puzzle[squareIndex].cells[cellIndex].value == 0){
                    int currentCell = squareIndex * gridSize + cellIndex;
                    //Eliminate possibilites:
                    eliminate(possible, puzzle, squareIndex, cellIndex);
                }

                //If there's only one possibility, set the cell's value
                if(possible[squareIndex * gridSize + cellIndex].size() == 1){
                    int value = possible[squareIndex * gridSize + cellIndex][0]; //The single possible value
                    puzzle.puzzle[squareIndex].cells[cellIndex].value = value;
                    
                    //Clear possibilities for this cell (no longer needed)
                    possible[squareIndex * gridSize + cellIndex].clear();
                }
            }
        }
        //If it loops 50 times and there is no solution, break the while loop
        if(iter == 50){
            break;
        }
    }

    return puzzle;
}


int main(){
    menu();
}
