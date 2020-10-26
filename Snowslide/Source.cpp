#include <iostream>
#include <string>
using namespace std;

int selection(int);
int movement(int, int, int, int, int, int, int);

//variable to track how far from climb spot
int climb = 2;
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

	//variable to track which space the player lands on
	int space = { 0 };
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
			cout << "You are on a CLIMB space! To ascend to the next level, you must play a 1.";
		}
		cout << "1: " << card1 << "\n";
		cout << "2: " << card2 << "\n";
		cout << "3: " << card3 << "\n";
		
		while (layer != 4)
		{

		//runs the function to pick cards
		selection(play);
		
		//runs the movement function
		if (play == 1 || play == 2 || play == 3)
		{
			movement(play, climb, card1, card2, card3, layer, space);

			main();
		}
			cout << "You are currently " << climb << " spaces from the next rope spot. How far would you like to move?\n";
			cout << "1: " << card1 << "\n";
			cout << "2: " << card2 << "\n";
			cout << "3: " << card3 << "\n";
			cin >> play;

		
			//runs the movement function
			movement(play, climb, card1, card2, card3, layer, space);
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

		while (restart != 'y' && restart != 'n')
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


int movement(int play, int climb, int card1, int card2, int card3, int layer, int space)	//Function for player movement
{
	//changes climb based on which card is played
	int overflow;

	if (layer == 1)
	{
		climb = climb - card1;

		//randomize a new card
		card1 = (rand() % 6) + 1;
		return card1;
		
		//corrects position if they go past the climb space
		if (climb < 0)
		//if the player played card 1
		if (play == 1)
		{
			climb = climb + 6;
			//adds the card number to the space number
			space = space + card1;
			card1 = (rand() % 6) + 1;

			if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a black space. Nothing happens.\n";

				if (space == 0)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 4)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 8)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 12)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 16)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				climb = 2;
			}

			if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a blue space. Take a rest.\n";

				if (space == 1)
				{
					std::cout << "You are 1 space away from the climb space.\n";
				}

				if (space == 5)
				{
					std::cout << "You are 1 space away from the climb space.\n";
				}

				if (space == 9)
				{
					std::cout << "You are 1 space away from the climb space.\n";
				}

				if (space == 13)
				{
					std::cout << "You are 1 space away from the climb space.\n";
				}

				if (space == 17)
				{
					std::cout << "You are 1 space away from the climb space.\n";
				}

				climb = 1;
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 2.\n";

				//displays the cards for the player to pick
				cout << "1: " << card1 << "\n";
				cout << "2: " << card2 << "\n";
				cout << "3: " << card3 << "\n";
				cin >> play;

				//checks to see if the card's value is 1
				if (play == 1 && card1 == 1)
				{
					layer++;
				}

				if (play == 2 && card2 == 1)
				{
					layer++;
				}

				if (play == 3 && card3 == 1)
				{
					layer++;
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 2 && layer == 2)
				{
					space = 0;
				}

				if (space == 6 && layer == 2)
				{
					space = 3;
				}

				if (space == 10 && layer == 2)
				{
					space = 6;
				}

				if (space == 14 && layer == 2)
				{
					space = 9;
				}

				if (space == 18 && layer == 2)
				{
					space = 12;
				}


			}

			if (space == 3 || space == 7 || space == 11 || space == 15 || space == 19)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a chance space. Pull a chance card.\n";

				if (space == 3)
				{
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (space == 7)
				{
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (space == 11)
				{
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (space == 15)
				{
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (space == 19)
				{
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				climb = 3;
			}
				if (climb < 0)
				{
					overflow = climb * -1;
				}
			

			//if the player played card 2
			if (play == 2)
			{
				//adds the card number to the space number
				space = space + card2;
				card2 = (rand() % 6) + 1;

				if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a black space. Nothing happens.\n";


					if (space == 0)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 4)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 8)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 12)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 16)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					climb = 2;
				}

				if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a blue space. Take a rest.\n";


					if (space == 1)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 5)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 9)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 13)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 17)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					climb = 1;
				}

				if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
				{
					//tells the system that the player is on a climb space
					climb = 0;

					//tells player where they landed and what happens
					std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 2.\n";

					if (space == 2 && layer == 2)
					{
						space = 0;
					}

					if (space == 6 && layer == 2)
					{
						space = 3;
					}

					if (space == 10 && layer == 2)
					{
						space = 6;
					}

					if (space == 14 && layer == 2)
					{
						space = 9;
					}

					if (space == 18 && layer == 2)
					{
						space = 12;
					}

					layer++;
				}

				if (space == 3 || space == 7 || space == 11 || space == 15 || space == 19)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a chance space. Pull a chance card.\n";

					if (space == 3)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 7)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 11)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 15)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 19)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					climb = 3;
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
				card3 = (rand() % 6) + 1;

				if (space == 0 || space == 4 || space == 8 || space == 12 || space == 16)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a black space. Nothing happens.\n";

					if (space == 0)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 4)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 8)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 12)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					if (space == 16)
					{
						std::cout << "You are 2 spaces away from the climb space.\n";
					}

					climb = 2;
				}

				if (space == 1 || space == 5 || space == 9 || space == 13 || space == 17)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a blue space. Take a rest.\n";

					if (space == 1)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 5)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 9)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 13)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					if (space == 17)
					{
						std::cout << "You are 1 space away from the climb space.\n";
					}

					climb = 1;
				}

				if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
				{
					//tells the system that the player is on a climb space
					climb = 0;

					//tells player where they landed and what happens
					std::cout << "You have landed on a climb space. You are now on You must now pick up a chance card and play a 1 to go up to layer 2.\n";

					if (space == 2 && layer == 2)
					{
						space = 0;
					}

					if (space == 6 && layer == 2)
					{
						space = 3;
					}

					if (space == 10 && layer == 2)
					{
						space = 6;
					}

					if (space == 14 && layer == 2)
					{
						space = 9;
					}

					if (space == 18 && layer == 2)
					{
						space = 12;
					}

					layer++;
				}

				if (space == 3 || space == 7 || space == 11 || space == 15 || space == 19)
				{
					//tells player where they landed and what happens
					std::cout << "You have landed on a chance space. Pull a chance card.\n";

					if (space == 3)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 7)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 11)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 15)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					if (space == 19)
					{
						std::cout << "You are 3 spaces away from the climb space.\n";
					}

					climb = 3;
				}

				if (climb < 0)
				{
					overflow = climb * -1;
				}
			}
		}
		//moves them up a layer if 1 is played
		if (climb == 0 && card1 == 1)
		{
			climb = 5;
			layer++;
		}
	}

	if (layer == 2)
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

	if (layer == 3)
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
	return layer;
}