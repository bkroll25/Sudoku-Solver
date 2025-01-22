#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

//Data structures:
//The individual Cell
class Cell{
    public:
        int value; 

        bool operator==(const Cell& other) const {
            return value == other.value;
        }

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

        bool operator==(const Square& other) const{
            return cells == other.cells;
        }

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
        vector<Square> solution;
        vector<Square> puzzle;

        bool isValid(int row, int col, int num);
        bool inSquare(int row, int col, int num);
        bool inRow(int row, int num);
        bool inCol(int col, int num);

        bool fillBoard(int row, int col);
        void generateFilledBoard();
        void generatePuzzle(int blanks);

    //Constructors:
    Board(){
        length = 9;
        amount = length * length;
        solution.resize(length, Square(3));
        
        this->generateFilledBoard();
    }
    Board(int len){
        length = len;
        amount = length * length;
        solution.resize(length, Square(sqrt(length)));

        this->generateFilledBoard();
    }
};

//Helper functions:
void printBoard(vector<Square> sudoku, int length);

#endif