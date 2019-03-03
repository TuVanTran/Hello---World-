#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int Player1, Player2;
	string Player1Guess, Player2Guess;
	int turn, gameover, choice;
	string Computer;
	char restart = 0;
	cout << "Welcome to rock, paper, and scissor game competition";
	srand(static_cast<unsigned int>(time(NULL)));
	choice = rand() % 3 + 1;
	if (choice == 1)
		Computer = "rock";
	else if (choice == 2)
		Computer = "paper";
	else
		Computer = "scissor";

	while (gameover == false)
	{
		cout << "\nNow two of you guys will against computer guess and let see who will win?";
		cout << "\nFirst I need your information";
		cout << "\nPlayer1 name: ";
		cin >> Player1;
		cout << "\nPlayer2 name: ";
		cin >> Player2;
		cout << "Hi! " << Player1 << ", " << Player2 << " welcome to the game!";
		cout << "\nYou will choose rock, paper, or scissor to compare with computer!";
		cout << "\nLet's start!";

		turn = (rand() % 2);

		cout << Player1 << ", what is your choice: ";
		cin >> Player1Guess;

		cout << Player2 << ", what is your choice: ";
		cin >> Player2Guess;

		if (Computer == "rock" && Player1Guess == "rock" && Player2Guess == "rock")
		{
			cout << Player1 << "It was tie" << endl;
			cout << Player2 << "It was tie" << endl;
		}
		else if (Computer == "rock" && Player1Guess == "paper" && Player2Guess == "paper")
		{
			cout << Player1 << ", you win";
			cout << Player2 << ", you win";
		}
		else if (Computer == "rock" && Player1Guess == "scissor" && Player2Guess == "scissor")
		{
			cout << Player1 << ", you lose";
			cout << Player2 << ", you lose";
		}
		else if (Computer == "paper" && Player1Guess == "paper" && Player2Guess == "paper")
		{
			cout << Player1 << "It was tie" << endl;
			cout << Player2 << "It was tie" << endl;
		}
		else if (Computer == "paper" && Player1Guess == "scissor" && Player2Guess == "scissor")
		{
			cout << Player1 << ", you win";
			cout << Player2 << ", you win";
		}
		else if (Computer == "paper" && Player1Guess == "rock" && Player2Guess == "rock")
		{
			cout << Player1 << ", you lose";
			cout << Player2 << ", you lose";
		}
		else if (Computer == "scissor" && Player1Guess == "scissor" && Player2Guess == "scissor")
		{
			cout << Player1 << "It was tie" << endl;
			cout << Player2 << "It was tie" << endl;
		}
		else if (Computer == "scissor" && Player1Guess == "rock" && Player2Guess == "rock")
		{
			cout << Player1 << ", you win";
			cout << Player2 << ", you win";
		}
		else if (Computer == "scissor" && Player1Guess == "paper" && Player2Guess == "paper")
		{
			cout << Player1 << ", you lose";
			cout << Player2 << ", you lose";
		}
		else if (gameover == true)
			cout << "\nDo you want to play again?";
			cout << "\nYou can choose 'y' to continue or 'n' to end the game" << endl;
			cout << Player1 << ", " << Player2 << ": Enter your choice: ";
			cin >> turn;
			if (restart == 'y')
				gameover == false;
			else
			{
				gameover == true;
				cout << "Hope you has a good game!" << "\nBye" << endl;
			}

	}

	system("pause");
	return 0;
}