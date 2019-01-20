#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int Guesses = 6;
	int Guess;
	int Answer;
	int Player = 2;

	srand(time(NULL));
	Answer = 45 ;

	cout << "Welcome to the Guess Game.\n" << "Class GAME FUNDAMENTALS I CRN-45629-201802\n\n";
	cout << "We are going to guess a number from 1 to 100\n" << "We will have " << Player << " players\n";
	for (int i = 0; i < Player; i++)
	{
		cout << "Player 1 #" << ((i + 1) <= 3) << ":";
		cin >> Guess;
		if (Guess != Answer)
		{
			if (Guess > Answer)
				cout << "Too high.\n";
			else
				cout << "Too low.\n";
		}
		else

		{
			if (Player = Answer)
				cout << "Congratulation! You got it.\n";
			else
			{
				cout << "You lose";
			}
		}

		cout << "Player 2 #" << ((i + 1) <= 3) << ":";
		cin >> Guess;
		if (Guess != Answer)
		{
			if (Guess > Answer)
				cout << "Too high.\n";
			else
				cout << "Too low.\n";
		}
		else

		{
			cout << "Congratulation! You got it.\n";
		}
	
	}
	cout << "You lost.\n" << "Try one more time maybe you will win.\n";
	system("pause");
	return 0;
}