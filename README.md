# Sudoku-Solver
A program to generate and solve sudoku puzzles of varying sizes or difficulties


This is a personal project just to show off programming skill. I have worked on it a bit before but this time I am going to work on it until it is fully finished. 
Some goals as of 1/13/2025:

+ Generate Sudoku boards of the regular size (9x9)
+ Solve a regular Sudoku board
+ Make the above code modular so it can solve irregular sizes
+ Generate an irregular board (4x4 or 16x16 perhaps?)
+ Solve the irregular boards (hopefully without changing code)

Flex goals:
+ Different types of Sudoku boards? (Like the examples here: https://sudoku-puzzles.net/sudoku-variations/)
+ Make the Sudoku puzzles "good" like outlined on this paper: [chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/https://www.sudokuwiki.org/Sudoku_Creation_and_Grading.pdf](https://www.sudokuwiki.org/Sudoku_Creation_and_Grading.pdf)

I will be using https://github.com/norvig/pytudes/blob/main/ipynb/Sudoku.ipynb as a guide for when I get stumped, so thank you very much to Peter Norvig for the help.


Terms I am using:
+ Board: The full Sudoku board
+ Regular Board: a 9x9 Sudoku board, which is the regular size for one
+ Length: the length of one side of the board, which should be equal to the other side
+ Square: the subgrid of a sudoku board, that is  the sqrt of the length of the board (in a 9x9 board there are 9 3x3 squares)
+ Cell: The single digit in a board (in a 9x9 board there are 81 cells, or 9 cells per square)
+ N: Usually I will use this to denote the length (also shown as 'n')
+ Amount: shorthand for how many cells are in a set area, it should always be equal to length squared. 
