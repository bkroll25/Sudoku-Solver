#include <iostream>
#include <random>
#include "Sudoku.h"

using namespace std;

//Braden Kroll
//1/13/2025
/*
+ This program is the menu system that is used to run the algorithms that create and solve the sudoku boards
*/
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
            
        }else if(userInput == 'q' || userInput == 'Q'){
            //Quit
            break;
        }else{
            //Incorrect input
            cout<<"Incorrect input, please try again"<<endl<<endl;
        }
    }
}


int main(){
    menu();
}
