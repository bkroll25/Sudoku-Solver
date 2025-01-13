#include <iostream>
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
        cout<<"[2] Create a nxn size puzzle"<<endl;
        cout<<"[q] Quit"<<endl<<endl;

        //Take in input
        cout<<"Input: ";
        cin>>userInput;
        cout<<endl;

        //Actual Menu:
        if(userInput == '1'){
            //9x9 Sudoku Board
            Board sudoku;
            printBoard(sudoku);

        }else if(userInput == '2'){
            //nxn Sudoku Board
            
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
