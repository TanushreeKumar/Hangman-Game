#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
bool run;
string input;
string hidden_word = "";

class Hangman
{
private:

char *response=" " ; //This stores the word to be guessed

string shown=""; //This is used to show user how far they have gotten in guessing

string hint ; //hint for the word to be guessed

int p1_count = 0 ; // count of number of rounds won by Player 1

int p2_count = 0 ; // count of number of rounds won by Player 2

int count = 1 ; // total rounds played

string p1 = "Player 1" ; // default name of Player 1, which can be changed in the Menu

string p2 = "Player 2" ; // default name of Player , which can be changed in the Menu

public :
HANDLE H_Console = GetStdHandle(STD_OUTPUT_HANDLE); // handle to the output device

void gotoXY(int X, int Y)
{
COORD position;
position.X = X;
position.Y = Y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void printBox(int X, int Y, int width, int length)
{
char U_L_C = 201, U_R_C = 187, L_L_C = 200, L_R_C = 188;

char H_L = 205, V_L = 186;

width -= 2; length -= 2;

//Printing horizontal line
gotoXY(X, Y);
cout << U_L_C;

for (int i = 0; i < width; i++)
cout << H_L;

cout << U_R_C;
//Printing vertical lines
for (int i = 0; i < length; i++)
{
gotoXY(X, Y + (i + 1));
cout << V_L;
gotoXY(X + (width + 1), Y + (i + 1));
cout << V_L;
}
//Printing horizontal line
gotoXY(X, Y + length);
cout << L_L_C;

for (int i = 0; i < width; i++)
cout << H_L;

cout << L_R_C;
}
void clearScreen()
{
// Clearing screen from point (3,3) to (77,27)
for (int i = 0; i < 24; i++)
{
gotoXY(3, 1 + i);

for (int j = 0; j < 74; j++)
cout << " ";
}
}
void hangmanGame()
{
while (true)
{
clearScreen();
char logo[7][75];
strcpy(logo[0], "HH    HH     AA     NN    NN     GGG    MM          MM     AA     NN    NN");
strcpy(logo[1], "HH    HH   AA  AA   NNN   NN   GG   GG  MMM        MMM   AA  AA   NNN   NN");
strcpy(logo[2], "HH    HH  AA    AA  NNNN  NN  GG        MMMM      MMMM  AA    AA  NNNN  NN");
strcpy(logo[3], "HHHHHHHH  AAAAAAAA  NN NN NN  GG        MM MM    MM MM  AAAAAAAA  NN NN NN");
strcpy(logo[4], "HH    HH  AA    AA  NN  NNNN  GG   GGG  MM  MM  MM  MM  AA    AA  NN  NNNN");
strcpy(logo[5], "HH    HH  AA    AA  NN   NNN   GG   GG  MM   MMMM   MM  AA    AA  NN   NNN");
strcpy(logo[6], "HH    HH  AA    AA  NN    NN     GGG    MM    MM    MM  AA    AA  NN    NN");

//Printing logo
for (int i = 0; i < 7; i++)
{
SetConsoleTextAttribute(H_Console, 6);
gotoXY(3, 1 + i);
puts(logo[i]);
}

SetConsoleTextAttribute(H_Console, 6);

printBox(28, 8, 42, 14); // box for the menu

printBox(14, 22 , 22 , 4) ; //player1 score box

printBox(46, 22 , 22 , 4) ; //player2 score box
//menu starts
/*---------------------------MENU-------------------------*/
gotoXY(31, 10);
cout << "(1)->  Play game with another person ";

gotoXY(31, 12);
cout << "(2)->  Change Names ";

gotoXY(31, 14);
cout << "(3)-> How to play";

gotoXY(31, 16);
cout << "(4)-> Select Level";

gotoXY(31, 18);
cout << "(5)->    Exit    ";

gotoXY(18,23) ;
cout<<p1<<" : "<<p1_count ; //display player 1 name and score

gotoXY(50,23) ;
cout<<p2<<" : "<<p2_count ; //display player 2 name and score

//Selecting option
gotoXY(0, 29);
char ch = getch();

if (ch == '1')
startGame(); //play game

else if (ch=='2') // take player 1 and player 2 name as input
{
SetConsoleTextAttribute(H_Console, 6);
clearScreen() ;
gotoXY(31, 16);
cout<<"Player 1 : " ;
gotoXY(31,18) ;
getline(cin,p1) ;
gotoXY(31, 20);
cout<<"Player 2 : " ; //scanf("\n") ;
gotoXY(31,22) ;
getline(cin,p2) ;
continue ;
}
else if (ch == '3')
  instructions(); //display instructions

else if (ch == '4') //take word to be guessed and hint as input
{
SetConsoleTextAttribute(H_Console, 6);
clearScreen() ;
char input[100] ;
gotoXY(31, 16);
cout<<"Enter the level 1.beg 2.med 3.hard" ; //enter word to be guessed
gotoXY(31,18) ;
cin>>input ;
storetheword(input) ; //store word
continue ;
       }
else if (ch == '5'){
   clearScreen();
   gotoXY(31,16);
                    if(p1_count>p2_count){
                        cout << "PLAYER 1 WINS !!!";
                    }
                    else{
                        cout << "PLAYER 2 WINS !!!";
                    }
                        gotoXY(31,18);
exit(0); //exit program
}

else
continue;
}
}
void startGame()
{
if(response=="" or strlen(response)<=1)  // if initially no word is entered or word has only one letter, user is asked to enter a valid word
{
SetConsoleTextAttribute(H_Console, 6);
clearScreen() ;
gotoXY(25, 12);
cout<<"Enter a valid level!" ;
gotoXY(25, 14);
cout<<"Press any key to return to Menu" ;
char any = getch() ;
return ;
}
while (true)
{
count+=1 ; //total rounds is incremented by one
playGame(); // game starts
// int check = 0;
char chek = getch() ; // after the round, control returns here, from where it is redirected back to hangmanGame()
break ;
}
hangmanGame();
}
void instructions()
{
SetConsoleTextAttribute(H_Console, 6);
clearScreen() ;
char about[19][78];
strcpy(about[0], "                                :: HANGMAN ::                                ");
strcpy(about[1], "                                                                             ");
strcpy(about[2], "                   In this game, you have to guess a word!                   ");
strcpy(about[3], "                           ");
strcpy(about[4], "                                                                             ");
strcpy(about[5], "                 You will have 7 lives for guessing the word                 ");
strcpy(about[6], "                        If you guessed the word right                        ");
strcpy(about[7], "                       you win the round!               ");
strcpy(about[8], "                                                                             ");
strcpy(about[9], "                But if you're not able to guess the word and                 ");
strcpy(about[10], "                   lives finish then you lose the round!                    ");
strcpy(about[11], "                                                                            ");
strcpy(about[12], "                     First, Player 1 must enter word to be                   ");
strcpy(about[13], "                                                                             ");
strcpy(about[14], "                          guessed, along with the hint                       ");
strcpy(about[15], "                                                                             ");
strcpy(about[16], "                         Player 2 will try to guess the word                 ");
strcpy(about[17], "                                                                             ");
strcpy(about[18], "                          Positions swap after each round                    ");
//printing Instruction
for (int i = 0; i < 19; i++) {
gotoXY(1, 5 + i);
puts(about[i]);
}
gotoXY(0, 29);
getch();
hangmanGame();
}
void storetheword(char *x)//simply storing the secret phrase in a private member
{
   response=x;
}
void hanging(int wrong)
{

static char hang[12][20];

if (wrong == 0)
{
strcpy(hang[0], " _____    ");
strcpy(hang[1], " |           |    ");
strcpy(hang[2], " |           |    ");
strcpy(hang[3], "             |    ");
strcpy(hang[4], "             |   ");
strcpy(hang[5], "             |    ");
strcpy(hang[6], "             |   ");
strcpy(hang[7], "             |    ");
strcpy(hang[8], "             |    ");
strcpy(hang[9], "             |    ");
strcpy(hang[10], "             |    ");
strcpy(hang[11], "         ---------");
}

else if (wrong == 1)
strcpy(hang[3], " O           |    ");

else if (wrong == 2)
strcpy(hang[4], " |           |   ");

else if (wrong == 3)
strcpy(hang[4], "/|           |   ");

else if (wrong == 4)
strcpy(hang[4], "/|\\          |   ");

else if (wrong == 5)
strcpy(hang[5], " |           |    ");

else if (wrong == 6)
strcpy(hang[6], "/            |   ");

else
strcpy(hang[6], "/ \\          |   ");
//Displaying man hanging
for (int i = 0; i < 12; i++)
{
if (wrong == 7)
SetConsoleTextAttribute(H_Console, 6);
gotoXY(49, 11 + i);
puts(hang[i]);
}
if (wrong == 7)
SetConsoleTextAttribute(H_Console, 6);
}
void playGame()
{
clearScreen();
int lives = 0, check = 0;
char* guess  ; // a variable guess is used to encrypt the word to be guessed , input is the guessed character
char input;
string word; //word to be guessed
//Getting and storing level
word = getWord();
//Converting word into astericks
encryptWord(word, guess);
//Boxes to display tries left, the hangman, etc
printBox(10, 3, 19, 4);
printBox(56, 3, 14, 4);
printBox(46, 9, 24, 17);
while (true)
{
//Printing word to guess
gotoXY(12, 4);
cout << "Word : ";
cout<< guess;

gotoXY(58, 4);
cout << "Lives : " << (7 - lives);
//Displaying man hanging
hanging(lives);
if (lives == 7) //If lives are finished
break;
if (checkWord(word, guess))
{ //If word has been guessed
check = 1;
break;
}
//Taking guess
gotoXY(12, 11);
cout << "Enter your guess : ";
input = getche();
gotoXY(14, 14);
                const char* str = word.c_str();
if (checkGuess(str, guess, input))
{
//If guessed character is found
cout << "                        ";
gotoXY(14, 14);
cout << "Good guess!";
}
else
{
//If guessed character isn't found
cout << "One step closer to death";
lives++; //lives is incremented and once it reaches 7, player loses
}
}
//Printing result
printBox(10, 18, 25, 8);
SetConsoleTextAttribute(H_Console, 6);
gotoXY(18, 20);

if (check == 1)
{ //if word is guessed correctly check is set to 1
cout << "YOU WIN!";
/* if count is odd, player 1 is currently playing, otherwise it's player 2*/
if (!(count&1)) // if count is odd
p1_count+=1 ; //increment score of player 1 by 1

else //if count is even
p2_count+=1 ; //increment score of player 2 by 1
}

else //if player has run of tries and word isn't correct
cout << "YOU LOSE!";

SetConsoleTextAttribute(H_Console, 6);
}
void encryptWord(string word, char* guess)
{
int i = 1;
            const int length1 = word.length();
            // declaring character array (+1 for null terminator)
            char* char_array1 = new char[length1 + 1];
            // copying the contents of the
            // string to char array
            strcpy(char_array1, word.c_str());
//Storing first character of word as it is
guess[0] = char_array1[0];
//Storing all other characters of word as astericks
while (char_array1[i] != '\0')
{
guess[i] = '*';
i++;
}
//Storing NULL at the last index
guess[i] = '\0';
}
bool checkGuess(string word , char* guess, char ch)
{
bool check = false;
int i = 0;
//Converting character to uppercase
ch = toupper(ch);

char temp ; //temp variable to store uppercase of word

while (word[i] != '\0')
{
temp = toupper(word[i]);
if (temp == ch)
{
                    //If character is found in word
guess[i] = word[i]; //store character in guess, thus revealing all occurences of the character guessed
check = true; //set check as true, i.e., guessed character is valid
}
i++; //increment i to check next index
}
return check;
}
bool checkWord(string word, char* guess)
{
int i = 0;
while (word[i] != '\0') {
if (word[i] != guess[i]) //If any character didn't matched
return false;
i++;
}
return true;
}
int countLines(vector<string> words) {
    return words.size();
}
string getWord() {
    ifstream words_file;
    try {
        if(strcmp(response, "beg") == 0){
            words_file.open("beg.txt");
        }
        else if(strcmp(response, "med") == 0){
            words_file.open("med.txt");
        }
        else {
            words_file.open("hard.txt");
        }
    }
    catch (...) {
        cout << "Error" << endl;
        run = false;
    }
    string line;
    vector<string> words;
    while (getline(words_file,line)) {
        words.push_back(line);
    }
    words_file.close();
    srand(time(NULL));
    int number_of_words = countLines(words);
    string word = words.at(rand() % number_of_words);
    return word;
}
};

int main() {
    Hangman instance ; //create an object instance of class hangman
    system("title HANGMAN"); //Setting title
    system("mode 90,30"); //Setting screen mode
    system("color 02"); //Setting color

    instance.printBox(0, 0, 90, 30); //Printing box border
    instance.hangmanGame(); //Displaying menu
    cout << "Welcome to Hangman!" << endl;

    return 0;
}
