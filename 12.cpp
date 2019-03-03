#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int number, guess, Player1point = 100, Player2point = 100, count = 0;
	int option, cguess, gamover;
	string player1, player2;
	bool turn, gameover = false;                       // Set a condition 
	char restart = 0;                                 // Assign restart function to a character

	cout << "\n\n			Welcome to the Number Guessing Game\n\n" << endl << endl;
	cout << "	RULE: Each player take turn to guess for the right number (1-100)\n\n" << endl;
	cout << "Play option: 1. Player vs Player" << endl;
	cout << "             2. Player vs Computer" << endl;
	cout << "Enter 1 or 2 for different game mode...";
	cin >> option;
	cout << "\n				Let's start!\n\n";

	srand(time(0));
	cguess = number = rand() % 100 + 1;
	number = rand() % 100 + 1; // Randomnize 1-100
	turn = (rand() % 2);

	while (option != 1 && option != 2)
	{
		cout << "Invalid option! Please try again?\n";
		cin >> option;
	}

	if (option == 1)
	{
		cout << "You choose option 1 with 2 players!\n\nLet's go!\n\n";
		cout << "Player1 enter your name: " << endl;
		cin >> player1;
		cout << "\nPlayer2 enter your name: " << endl;
		cin >> player2;
		cout << "\nWelcome " << player1 << ", " << player2 << ". Let's see who has the better predictions.\n";
		cout << endl;
		while (gameover == false)
		{
			cout << (turn == 0 ? player1 : player2) << " Enter a number:"; // Randomnize player
			cin >> guess;                                            // Chosen player make the first guess

			if (guess > number && guess > 0 && guess < 100)
			{
				cout << "Your guess is too high! -5 point" << endl;
				cout << "Your point is: " << (turn == 0 ? (Player1point -= 5) : (Player2point -= 5)) << endl << endl;

			}
			else if (guess < number && guess > 0 && guess < 100)
			{
				cout << "Your guess is too low! -5 point" << endl;
				cout << "Your point is: " << (turn == 0 ? (Player1point -= 5) : (Player2point -= 5)) << endl << endl;

			}
			else if (guess < 0 || guess > 100)                       // Enter an out of bound guess would activate this statement
				cout << "You enter an invalid number, try from 1 to 100" << endl;
			else if (guess == number && guess > 0 && guess < 100)
			{
				cout << "YOU GOT THE RIGHT NUMBER" << endl;           // Break out of the guessing loop and into the restart option
				gameover = true;
				cout << (turn == 0 ? player1 : player2) << " Win!!!!" << endl;
				cout << (turn == 0 ? player1 : player2) << ", your finally score is: " << (turn == 0 ? Player1point : Player2point) << endl;
			}

			if (gameover == false && guess > 0 && guess < 100)        // False answer will switch up the player
				turn = !turn;

			else if (gameover == true)
			{
				cout << player1 << ", " << player2 << " would you two want a rematch (y/n)?" << endl;     // Restart option 
				cin >> restart;
			}
			if (gameover == true && restart == 'y')
			{
				number = rand() % 100 + 1;
				turn = (rand() % 2);                                 // Type yes will randomnize a new number and player turn
				cout << "So I have picked another number between 1-100 for you two. Let's begin" << endl;
				gameover = false;                                    // come back to guessing loop
			}
			else if (gameover == true && restart == 'n')
				cout << "It was fun, goodbye!" << endl;              // No = display goodbye message and end the game
		}
	}

	if (option == 2)
	{
		bool outofLives = false;  // Set flag for when run out of lives you loose
		int lives = 5;            // Set player health to 5
		cout << "	Welcome!!! No friends? No worries I'm here to play with you\n" << endl;
		cout << "			You will have 5 lives\n\n";
		cout << "		If your guess is wrong, you will lose 1 live!\n\n";
		cout << "				Let's go!\n\n";
		cout << "What is your name?" << endl;
		cin >> player1;           // Player name
		cout << "\nComputer: Let's see if you can outsmart me!... " << player1 << "?" << endl << endl;

		while (gameover == false)
		{
			cout << player1 << " Enter a number:";   // Ask for a guess
			cin >> guess;                            // Input a guess

			if (guess > number && guess > 0 && guess < 101)
			{
				cout << "Try entering a lower number" << endl;
				lives--;                                                 // Guess not right, deduces 1 live
				cout << "You lose 1 live" << endl;
				cout << "You have " << (lives ? lives : (lives--)) << " live left" << endl;
				cout << "\nCOM guess: " << cguess << endl; // Ask above stated, cguess is a randomnize number from 1-100
			}                                                            // Print COM guess on screen "cguess"
			else if (guess < number && guess > 0 && guess < 101)
			{
				cout << "Try entering a higher number" << endl;
				lives--;                                                  // Same as above
				cout << "You lose 1 live" << endl;
				cout << "You have " << (lives ? lives : (lives--)) << " live left" << endl;
				cout << "\nCOM guess: " << cguess << endl;
			}
			if (guess == number && guess > 0 && guess < 101)
			{
				cout << "\nYOU GOT THE RIGHT NUMBER!!!" << endl;          // Guess is correct, breaks out of guessing loop/win.
				cout << "\nCOM:You were cheating for sure, I'll have my revenge\n!!!" << endl;
				gameover = true;
			}
			else if (lives ? (lives <= 0) : (gameover = true))
			{
				cout << "\nYOU FOOL!!! YOU RAN OUT OF LIVES. I WON THIS GAME!!!\n" << endl;  // Runs out of live, breaks out of loop/loose.
				gameover = true;
			}
			else if (cguess != number && cguess > 0 && cguess < 101 && gameover != true)
			{
				cout << "COM: I'm just getting closer and closer to the number!\n" << endl;      // Computer guess is wrong? 
				srand(time(0));                                                                 // Randomnize another number from 1-100
				cguess = rand() % 100 + 1;
			}
			else if (guess < 1 || guess > 100)
			{
				cout << "\nYou enter an invalid number, try from 1 to 100" << endl;               // Guess that's out of bound?
				cout << "\nCOM: I said 1 to 100 you imbecile!" << endl;                          // The program harass you
			}

			if (cguess == number && lives > 0)
			{
				cout << "\nCOM: What did you expect challenging an advance being? I WON" << endl;
				gameover = true;                                                                // COM get the number (which is almost impossible)
			}

			else if (gameover == true)
			{
				cout << player1 << ", would you want play with me again? (y/n)" << endl;       // Ask to restart
				cin >> restart;
			}
			if (gameover == true && restart == 'y')                                            // Option to restart
			{
				number = rand() % 100 + 1;                             // Yes? Randomnized another number/ go back to vs COM mode
				cout << "\nCOM: So I have picked another number between 1-100 for us. Let's begin" << endl;
				option = 2;
				gameover = false;
			}
			else if (gameover == true && restart == 'n')               // No? End the program 
				cout << "\nCOM: I see you're afraid to face me again!" << endl;
		}
	}
	system("pause");
	return 0;
}