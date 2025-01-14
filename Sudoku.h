#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

//Data structures:
//The individual Cell
class Cell{
    public:
        int value; 

    //Constructors:
    Cell(){
        value = 0;
    }
    Cell(int num){
        value = num;
    }
};

//The subgrid thats the sqrt of the boards size:
class Square{
    public:
        int length;
        int amount;
        vector<Cell> cells;

    //Constructors
    Square(){
        length = 3;
        amount = length * length;
        cells.resize(amount, Cell());
    }
    Square(int len){
        length = len;
        amount = length * length;
        cells.resize(amount, Cell());
    }
};

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
        squares.resize(length, Square(3));
    }
    Board(int len){
        length = len;
        amount = length * length;
        squares.resize(length, Square(sqrt(length)));
    }
};

//Helper functions:
void printBoard(Board sudoku);


#endif