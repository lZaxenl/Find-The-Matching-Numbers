/* Author:		Jared Singleton (JaredSingleton@muy.unt.edu)
   Date:		6/ ??????? /2021
   Instructor:	Dr. Pradhumna Shrestha
   Description:	This program will design a game that guesses the locatoin of a pair
   				of numbers in a matrix with hidden elements.
*/

//FIXME: update the date above once complete

#include <iostream>
#include <ctime>	  	// for time(0)
#include <cstdlib> 		// for srand()
#include <iomanip>
using namespace std;

int main() 
{
	
	const int SIZE = 5;			// Constant size of the rows and columns
	int coord1;					// Coordinates for the row selected
	int coord2;					// Coordinates for the column selected
	double wins = 0;			// Number of games won
	double loses = 0;			// Number of games lost
	double games = 0;			// Total number of games played
	double percentage;			// Percentage of games won
	bool coord_valid;					
	bool playAgain;						// Does the player want to play agian
	int hidden_board[SIZE][SIZE];		// Hidden board; player can't see it
	int disp_board[SIZE][SIZE];			// Display board; player can see it
	int coord_arr[SIZE][SIZE] = {{0,0,0,0,0},
				  			     {0,0,0,0,0},
				  		 	     {0,0,0,0,0},
				 			     {0,0,0,0,0},
				 			     {0,0,0,0,0}};

	//************************************************************
	
	cout << "			|-----------------------------------------------|" << endl;
	cout << "			|	Computer Science and Engineering	|" << endl;
	cout << "			|	 CSCE 1030 - Computer Science I		|" << endl;
	cout << "			|	   Jared Singleton - 11355005 		|" << endl;
	cout << "			|	   JaredSingleton@my.unt.edu		|" << endl;
	cout << "			|-----------------------------------------------|" << endl;
	cout << endl << endl;
	
	do { // A loop that asks the player if they want to play agin
	
	
		
		//************************************************************
		// 					Generate Hidden Board
		
		srand(time(0));
		int randNum;	// generate random numbers for hidden board
		
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				hidden_board[i][j] = rand() % 25 + 1;
				
			}
		}
		
		//************************************************************
		// 			     Generate Display Board
		// Selecting the first coordinate to start the game
		
		do {
			for (int i = 0; i < SIZE; ++i) {
				for (int j = 0; j < SIZE; ++j) {
					disp_board[i][j] = -1;
				}
			}
			cout << "+---+-----------------------------------------+" << endl;
			cout << "|   |               Game Board                |" << endl;
			cout << "|   |    0       1       2       3       4    |" << endl;
			cout << "+---+-----------------------------------------+" << endl;
			for (int i = 0; i < SIZE; ++i) {
				cout << "| " << i << " |";
				for (int j = 0; j < SIZE; ++j) {
					cout << "\t" << disp_board[i][j];
				}
				cout << "    |" << endl;
			}
			cout << "+---+-----------------------------------------+" << endl;
			
			
			cout << "Enter a coordinate position that shows a '-1' (Ex. 1 2 ): ";
			cin >> coord1 >> coord2;
			cout << endl << endl << endl;
			if ((coord1 >= 0 && coord1 <= 4) && (coord2 >= 0 && coord2 <= 4)) {
				disp_board[coord1][coord2] = hidden_board[coord1][coord2];
				coord_valid = true;
			}
			else {
				cout << "*** ERROR: The coordinates you entered are out of range ***" << endl;
				coord_valid = false;
			}
			
			cout << endl;
		}while (coord_valid != true);
		
		coord_arr[coord1][coord2] = disp_board[coord1][coord2];
	
	
	//************************************************************
	// 						GAME STARTS HERE
		
		int Lives = 1;		// Number of tries user gets before game over
		bool match = false;	// If user guesses a position that matches one of their numbers
		
			do {
				// Display game board
				cout << "+---+-----------------------------------------+" << endl;
				cout << "|   |               Game Board                |" << endl;
				cout << "|   |    0       1       2       3       4    |" << endl;
				cout << "+---+-----------------------------------------+" << endl;
				for (int i = 0; i < SIZE; ++i) {
					cout << "| " << i << " |";
						for (int j = 0; j < SIZE; ++j) {
							cout << "\t" << disp_board[i][j];
						}
					cout << "    |" << endl;
				}
				cout << "+---+-----------------------------------------+" << endl;
				
				// How many lives you have
				if ( Lives > 1) {
					cout << "\t  You have a total of " << Lives << " Lives!!!" << endl;	
				}
				else {
					cout << "\t     You have " << Lives << " Life!!!" << endl;
				}
				cout << endl;
				
				
				cout << "Enter a coordinate position that shows a '-1' (Ex. 1 2 ): ";
				cin >> coord1 >> coord2;
				cout << endl << endl << endl;
				if ((coord1 >= 0 && coord1 <= 4) && (coord2 >= 0 && coord2 <= 4)) {
					// check if entered coordinates have already been entered
					if (disp_board[coord1][coord2] != coord_arr[coord1][coord2]) {
						bool match = false;								 															 			
						for (int i = 0; i < SIZE; ++i) {
							for (int j = 0; j < SIZE; ++j) {
								// check if display board numbers matche hidden board number at entered coordinates
								if (disp_board[i][j] == hidden_board[coord1][coord2]) { 
									match = true;
									break;
								}
							}
						}
						if (match) { // Displays that you won the game
							cout << "***************************************************" << endl;
							cout << "| You have matched the numbers on your board with |" << endl;
							cout << "| the hidden number at the coordinates you enterd.|" << endl;
							cout << "|                                                 |" << endl;
							cout << "|            *** You won the game! ***            |" << endl;
							cout << "***************************************************" << endl;
							cout << endl << endl << endl;
							++wins;
							Lives = 0;
							break;
						}
						else if (Lives > 1) { // Displays that your numbers do NOT match
							cout << "*** Your coordinates did not reveal a match ***" << endl;
							disp_board[coord1][coord2] = hidden_board[coord1][coord2];
							coord_arr[coord1][coord2] = disp_board[coord1][coord2];
							--Lives;
							continue;
						}
						else { // Displays that you lost the game
							cout << "**************************************************" << endl;
							cout << "|            You have run out of Lives           |" << endl;
							cout << "|                  GAME OVER!!!                  |" << endl;
							cout << "|                                                |" << endl;
							cout << "**************************************************" << endl;
							cout << endl << endl << endl;
							++loses;
							--Lives;
							continue;
						}
					}
					else { // Displays for repeated coordintes entered
						cout << "*** ERROR: You have already enterd those coordinates ***" << endl;
					}
				} 
							// Displays if coordinates are out of range
				else if ((coord1 > 4 || coord1 < 0) || (coord2 > 4 || coord2 < 0)){
					cout << "*** ERROR: The coordinates you entered are out of range ***" << endl;
				}
			} while (Lives != 0);
	

	//************************************************************
	//        Ask user if they want to play again
	
	
		char yesORno;
		do {
			cout << "Do you want to play again (Y/N)? ";
			cin >> yesORno;
			cout << endl;
			yesORno = toupper(yesORno);
			if (yesORno == 'Y') {
				playAgain = true;
				break;
			}
			else if (yesORno == 'N') {
				playAgain = false;
				break;
			}
			else {
				cout << "You entered an incorrect response." << endl;
				continue;
			}
		}while (playAgain != true || playAgain != false);
	} while (playAgain);
	cout << endl << endl;
	
	games = loses + wins;
	percentage = (wins / games) * 100;
	
	printf ("You won %.2lf%% of the games. Goodbye!!!\n", percentage); 
	
	return 0;
}





