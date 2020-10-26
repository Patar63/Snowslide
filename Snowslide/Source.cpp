#include <iostream>
#include <string>
using namespace std;

int movement(int, int, int, int, int, int);
int selection(int);

//variable to track how far from climb spot
int climb = 5;
//variable to track which level you're on
int layer = 1;
char input;
bool start = false;
int card1 = (rand() % 6) + 1;
int card2 = (rand() % 6) + 1;
int card3 = (rand() % 6) + 1;

int main()
{
	//initializes the needed variables
	string enterPressed;
	//store place for value of which card gets played by the player
	int play{};
	char restart;

	//starts up game so player can choose when to begin
	if (start == false)
	{
		cout << "You are a new hiker, determined to climb the mountain in front of you. Good luck, and be careful of snowslides.\n";
		cout << "Please note that you can not go up more than one layer using the same CLIMB space.\n";
		cout << "Press Enter to start...\n";
		getline(cin, enterPressed);
	}

	if (enterPressed.empty())
	{
		//randomizes cards in hand
		start = true;

		//gets the wanted move spaces from player 
		cout << "GAME START!!!\n";
		if (climb > 0)
		{
			cout << "You are currently " << climb << " spaces from the next rope spot. How far would you like to move?\n";
		}
		else
		{
			cout << "You are on a CLIMB space! To ascend to the next level, you must play a 1.";
		}
		cout << "1: " << card1 << "\n";
		cout << "2: " << card2 << "\n";
		cout << "3: " << card3 << "\n";

		//runs the function to pick cards
		selection(play);
		
		//runs the movement function
		if (play == 1 || play == 2 || play == 3)
		{
			movement(play, climb, card1, card2, card3, layer);

			main();
		}
	}
	else
	{
		cout << "Sorry, but you pressed a wrong key";
	}

	//victory condition
	if (layer == 6)
	{
		start = false;
		cout << "Congrats! You made it all the way to the top! Would you like to restart? y/n\n";
		cin >> restart;

		while (restart != 'y' || restart != 'n')
		{
			if (restart == 'y')
			{
				main();
			}
			else if (restart == 'n')
			{
				exit(0);
			}
			else
			{
				cout << "Please enter y or n.\n";
			}
		}
	}
}


int selection(int play)	//Function to pick cards
{
	cin >> play;

	if (play > 3 || play < 1)
	{
		cout << "You must pick a useable card.";
		selection(play);
	}

	return play;
}


int movement(int play, int climb, int card1, int card2, int card3, int layer)	//Function for player movement
{
	//changes climb based on which card is played
	if (play == 1)
	{
		climb = climb - card1;

		//randomize a new card
		card1 = (rand() % 6) + 1;
		return card1;
		
		//corrects position if they go past the climb space
		if (climb < 0)
		{
			climb = climb + 6;
		}
		//moves them up a layer if 1 is played
		if (climb == 0 && card1 == 1)
		{
			climb = 5;
			layer++;
		}
	}
	else if (play == 2)
	{
		climb = climb - card2;

		card2 = (rand() % 6) + 1;
		return card2;

		if (climb < 0)
		{
			climb = climb + 6;
		}
		if (climb == 0 && card2 == 1)
		{
			climb = 5;
			layer++;
		}
	}
	else if (play == 3)
	{
		climb = climb - card3;
		
		card3 = (rand() % 6) + 1;
		return card3;

		if (climb < 0)
		{
			climb = climb + 6;
		}
		if (climb == 0 && card3 == 1)
		{
			climb = 5;
			layer++;
		}
	}

	//retruns value for where the player is on the board
	return climb;
	return layer;
}