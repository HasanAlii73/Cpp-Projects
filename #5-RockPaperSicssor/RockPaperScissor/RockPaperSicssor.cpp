#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
void printplayerchoice(int choice)
{
	if (choice == 1)
		cout << "Player Choice Is : Rock\n";
	else if (choice == 2)
		cout << "Player Choice Is : Paper\n";
	else
		cout << "Player Choice Is : Scissor\n";

}
void printcomputerchoice(int computerchoice)
{
	if (computerchoice == 1)
		cout << "Computer Choice Is : Rock\n";
	else if (computerchoice == 2)
		cout << "Computer Choice Is : Paper\n";
	else
		cout << "Computer Choice Is : Scissor\n";

}
int printwinner(int playerchoice, int computerchoice)
{
	if (playerchoice == computerchoice)
	{
		cout << "Round Winner : [No Winner] \n";
		return 0;
	}
	else if (playerchoice == 1 && computerchoice == 3)
	{
		cout << "Round Winner : [Player] \n";
		return 1;
	}
	else if(playerchoice == 2 && computerchoice == 1)
	{
		cout << "Round Winner : [Player] \n";
		return 1;
	}
	else if (playerchoice == 3 && computerchoice == 2)
	{
		cout << "Round Winner : [Player] \n";
		return 1;
	}
	else
	{
		cout << "Round Winner : [Computer] \n";
		return 2;
	}
}
int randnumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}
void color(int winner)
{
	if (winner == 1)
		system("color 2f");
	else if (winner == 2)
	{
		system("color 4f");
		cout << "\a";
	}
	else
		system("color 6f");
}
void Finalprintwinner(int playerscore, int computerscore)
{
	if (playerscore > computerscore)
		cout << "The Player\n";
	else if (playerscore < computerscore)
		cout << "The Computer\n";
	else
		cout << "No Winneer\n";
}
void playAgain()
{
	system("cls");

}
void startgame()
{
	int playerscore = 0, computerscore = 0, draw = 0;
	// Game rounds number
	cout << "How Many Rounds 1 to 10 ?\n";
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
	cout << "Round [" << i + 1 << "] begins : \n\n";
	// Player choice
	int playerchoice;
	cout << "Your Choice Is : [1]:Rock, [2]:Paper, [3]Scissor ?";
	cin >> playerchoice;
	cout << "==============  Round[" << i + 1 << "]  ==============\n\n";
	printplayerchoice(playerchoice);
	// Computer choice
	int computerchoice = randnumber(1, 3);
	printcomputerchoice(computerchoice);
	int winner;
	// The winner
	winner = printwinner(playerchoice, computerchoice);
	color(winner);
	cout << "======================================================\n\n";
	// Score counting
	if (winner == 1)
		playerscore++;
	else if (winner == 2)
		computerscore++;
	else
		draw++;
	}
	// End of the game and Scores bar
	cout << "          ==================== Game Over ! ==================\n\n";
	cout << "          ===================================================\n\n";
	cout << "          =================[ Game Resulsts ]=================\n\n";
	cout << setw(20) << "Game round : " << n << "\n";
	cout << setw(20) << "Player score : " << playerscore << "\n";
	cout << setw(20) << "Computer score : " << computerscore << "\n";
	cout << setw(20) << "Final Winner : "; Finalprintwinner(playerscore, computerscore);
	cout << "          ===================================================\n\n";
	// Again ?
	cout << "Do you want to play again ? (Y/N)";
	char x; cin >> x;
	if (x == 'Y' || x == 'y')
	{
		playAgain();
		startgame();
	}
}
int main()
{
	startgame();
	return 0;
}