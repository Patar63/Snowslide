#include <iostream>
#include <string>
using namespace std;

int movement(int, int, int, int, int);
int selection(int);

//variable to track how far from climb spot
int climb = 5;
//variable to track which level you're on
int layer = 1;
char input;

int main()
{
	//initializes the needed variables
	string enterPressed;
	int card1;
	int card2;
	int card3;
	//store place for value of which card gets played by the player
	int play{};

	//starts up game so player can choose when to begin
	cout << "You are a new hiker, determined to climb the mountain in front of you. Good luck, and be careful of snowslides.\n";
	cout << "Press Enter to start...\n";
	getline(cin, enterPressed);

	if (enterPressed.empty())
	{
		//randomizes cards in hand
		card1 = (rand() % 6) + 1;
		card2 = (rand() % 6) + 1;
		card3 = (rand() % 6) + 1;

		//gets the wanted move spaces from player 
		cout << "GAME START!!!\n";
		if (climb > 0)
		{
			cout << "You are currently " << climb << " spaces from the next rope spot. How far would you like to move?\n";
		}
		else
		{
			cout << "You are on a climb space! To ascend to the next level, you must play a 1";
		}
		cout << "1: " << card1 << "\n";
		cout << "2: " << card2 << "\n";
		cout << "3: " << card3 << "\n";

		//runs the function to pick cards
		selection(play);
		
		//runs the movement function
		if (play == 1 || play == 2 || play == 3)
		{
			movement(play, climb, card1, card2, card3);
		}
	}
	else
	{
		cout << "Sorry, but you pressed a wrong key";
	}
}


int selection(int play)
{
	cin >> play;

	if (play > 3 || play < 1)
	{
		cout << "You must pick a useable card.";
		selection(play);
	}

	return play;
}


int movement(int play, int climb, int card1, int card2, int card3)
{
	//changes climb based on which card is played
	if (play == 1)
	{
		climb = climb - card1;
		
		//corrects position if they go past the climb space
		if (climb < 0)
		{
			climb = climb + 6;
		}
	}
	else if (play == 2)
	{
		climb = climb - card2;

		if (climb < 0)
		{
			climb = climb + 6;
		}
	}
	else if (play == 3)
	{
		climb = climb - card3;

		if (climb < 0)
		{
			climb = climb + 6;
		}
	}

	//retruns value for where the player is on the board
	return climb;
}