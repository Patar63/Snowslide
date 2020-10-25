#include <iostream>
#include <string>
using namespace std;

char input;
int movement(int, int, int, int, int, int, int);

int main()
{
	//initializes the needed variables
	string enterPressed;
	//variable to track how far from climb spot
	int climb = 2;
	//variable to track which level you're on
	int layer = 1;
	int card1;
	int card2;
	int card3;

	//variable to track which space the player lands on
	int space = { 0 };
	//store place for value of which card gets played by the player
	int play;

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
		cout << "You are currently " << climb << " spaces from the next rope spot. How far would you like to move?\n";
		cout << "1: " << card1 << "\n";
		cout << "2: " << card2 << "\n";
		cout << "3: " << card3 << "\n";
		cin >> play;

		//runs the movement function
		movement(play, climb, card1, card2, card3, layer, space);
	}
	else
	{
		cout << "Sorry, but you pressed the wrong key";
	}
}

int movement(int play, int climb, int card1, int card2, int card3, int layer, int space)
{
	int overflow;

	if (layer == 1)
	{
		//if the player played card 1
		if (play == 1)
		{
			//adds the card number to the space number
			space = space + card1;

			if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a black space. Nothing happens.";
			}

			if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a blue space. Take a rest.";
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You are now on layer 2.";

				if (space == 2)
				{
					space = 0;
				}

				if (space == 6)
				{
					space = 3;
				}

				if (space == 10)
				{
					space = 6;
				}

				if (space == 14)
				{
					space = 9;
				}

				if (space == 18)
				{
					space = 12;
				}

				layer++;
			}
			
			if (climb < 0)
			{ 
				overflow = climb * -1;
			}
		}

		//if the player played card 2
		if (play == 2)
		{
			//adds the card number to the space number
			space = space + card2;

			if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a black space. Nothing happens.";
			}

			if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a blue space. Take a rest.";
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You are now on layer 2.";

				if (space == 2)
				{
					space = 0;
				}

				if (space == 6)
				{
					space = 3;
				}

				if (space == 10)
				{
					space = 6;
				}

				if (space == 14)
				{
					space = 9;
				}

				if (space == 18)
				{
					space = 12;
				}

				layer++;
			}

			if (climb < 0)
			{
				overflow = climb * -1;
			}
		}

		//if the player played card 3
		if (play == 3)
		{
			//adds the card number to the space number
			space = space + card3;

			if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a black space. Nothing happens.";
			}

			if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a blue space. Take a rest.";
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You are now on layer 2.";

				if (space == 2)
				{
					space = 0;
				}

				if (space == 6)
				{
					space = 3;
				}

				if (space == 10)
				{
					space = 6;
				}

				if (space == 14)
				{
					space = 9;
				}

				if (space == 18)
				{
					space = 12;
				}

				layer++;
			}

			if (climb < 0)
			{
				overflow = climb * -1;
			}
		}
	}

	if (layer == 2)
	{

	}

	if (layer == 3)
	{

	}

	////changes climb based on which card is played
	//if (play == 1)
	//{
	//	climb = climb - card1;
	//	
	//	if (climb < 0)
	//	{
	//		int overflow;
	//		overflow = climb * -1;

	//	}
	//}
	//else if (play == 2)
	//{
	//	climb = climb - card2;
	//}
	//else if (play == 3)
	//{
	//	climb = climb - card3;
	//}

	//retruns value for where the player is on the board
	return climb;
}