#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

//Data structures:
//The full Sudoku board
class Board{
    public:
        int length;
        int amount;
        vector<Square> squares;

    bool isValid(int row, int col);
    bool inRow(int num);
    bool inCol(int num);
    bool inSquare(int row, int col, int num);

    //Constructors:
    Board(){
        length = 9;
        amount = length * length;
    }
    Board(int len){
        length = len;
        amount = length * length;
    }
};

//The subgrid thats the sqrt of the boards size:
class Square{
    int length;
    int amount;
    vector<Cell> cells;

    //Constructors
    Square(){
        length = 3;
        amount = length * length;
    }
    Square(int len){
        length = len;
        amount = length * length;
    }
};

//The individual Cell
class Cell{
    int value; 

    //Constructors:
    Cell(){
        int value = 0;
    }
    Cell(int num){
        int value = num;
    }
};

//Helper functions:
void printBoard(Board sudoku);


#endif