HANGMAN GAME
# Description
Hangman is a paper pencil guessing game for two or more players. One player thinks of a word and the other tries to guess it by suggesting the letters. 
The word to guess is represented by a row of dashes, giving the number of letters. 
If the guessing player suggests a letter which occurs int word, the program writes it in all its correct positions. 
If the suggested letter does not occur in the word, the other player draws one element of the hangman diagram as a tally mark.
# Functionalities
iostream: - Input-output stream, member function to insert data into a stream (output) or extract data from a stream (input), and to control the format of data that you insert or extract [ #include <iostream>]. 

fstream: - File stream, use to move data from a file saved in the system
[ #include <fstream>]. It is use for file handling, to get words from the file (beg.txt, med.txt, hard.txt).

string: - A string is class that defines objects that be represented as stream of characters. In the code, it is used to get the names of the players and for the words from the file [#include <string>].

vector: - Vector is same as dynamic arrays and have ability to adjust size during insertion or deletion of elements. In the code, it is used for word size [#include <vector>].

window.h: - It is Window-specific header file for the Both C and C++ programming language which contains declarations of all the functions, all the macros and all the data types used by the functions and subsystems [#include <window.h>].

conio.h: - It is used to take input from the keyboard given by the user and display output on the screen [#include <conio.h>].

getWord( ): - This is function is defined by the user to get the word from files. Here we have used file handling, by using ifstream & try-catch blocks.

storetheLevel( ): - This is also a user defined function, here the word is storing the word. Eg: - level, response.
gotoXY( ): - It places cursor at a desired location on the screen. It is possible to change the cursor location on the screen using the gotoXY() function. It is used to clear screen at certain position, for printing too.

printbox( ): - This function is defined by the user to print the boxes. 

clearscreen( ): - This function is used to clear the screen. With use of gotoXY( ) function, we can clear screen from a particular position.

hangmangame( ): - This function is used to display Hangman logo, instruction, players names and levels. 

startgame( ): - This is used to initiate the game.

instructions( ): - This function is used to display the instructions to play the game by using hangman( ) function.

hanging( ): - This function is used to display the hanging man is the player guess the wrong letters. Every time the player guessed a wrong letter one-by-one the parts of hanging man will be displayed. 

playgame( ): - This function will let the players to enter letters, tells how many tries are left, at end of the game display either player win or lose.

checkguess( ): -This will check whether the guess is correct or not.

checkword( ): - This function will check whether the word matches the answer or not.

countlines( ): - This function counts the lines in the file, adjust the size of word by using vector. 

Class Hangman: - All the above functions are defined in the class hangman which will run when we define an object in the driver code => Hangman instance.







