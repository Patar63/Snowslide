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
	int space = 0;
	//store place for value of which card gets played by the player
	int play;

	//starts up game so player can choose when to begin
	cout << "You are a new hiker, determined to climb the mountain in front of you. Good luck, and be careful of snowslides.\n";
	cout << "Press Enter to start...\n";
	getline(cin, enterPressed);

	if (enterPressed.empty())
	{
		//randomizes cards in hand
		card1 = rand() % 6 + 1;
		card2 = rand() % 6 + 1;
		card3 = rand() % 6 + 1;
	
		//gets the wanted move spaces from player 
		cout << "GAME START!!!\n";
		
		cout << "You are currently " << climb << " spaces from the next climb space. How far would you like to move?\n";
		
		while (layer != 4)
		{			
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

			if (space > 19)
			{
				space = (space - 20) + card1;
			}

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
				card1 = rand() % 6 + 1;
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
				card1 = rand() % 6 + 1;
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 2.\n";

				card1 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
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

				card1 = rand() % 6 + 1;
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
				card1 = rand() % 6 + 1;
			}

		}

		//if the player played card 2
		if (play == 2)
		{
			//adds the card number to the space number
			space = space + card2;

			if (space > 19)
			{
				space = (space - 20) + card1;
			}

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
				card2 = rand() % 6 + 1;
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
				card2 = rand() % 6 + 1;
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 2.\n";

				card2 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
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

				card2 = rand() % 6 + 1;
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
				card2 = rand() % 6 + 1;
			}

		}

		//if the player played card 3
		if (play == 3)
		{
			//adds the card number to the space number
			space = space + card3;

			if (space > 19)
			{
				space = (space - 20) + card1;
			}

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
				card3 = rand() % 6 + 1;
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
				card3 = rand() % 6 + 1;
			}

			if (space == 2 || space == 6 || space == 10 || space == 14 || space == 18)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must play a 1 to go up to layer 2.\n";

				card3 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 4 spaces away from the climb space.\n";
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

				card3 = rand() % 6 + 1;
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
				card3 = rand() % 6 + 1;
			}
		}
	}

	if (layer == 2)
	{
		//if the player played card 1
		if (play == 1)
		{
			//adds the card number to the space number
			space = space + card1;

			if (space > 14)
			{
				space = (space - 15) + card1;
			}

			if (space == 0 || space == 3 || space == 6 || space == 9 || space == 12)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card1 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 0 && layer == 3)
				{
					space = 0;
				}

				if (space == 3 && layer == 3)
				{
					space = 2;
				}

				if (space == 6 && layer == 3)
				{
					space = 4;
				}

				if (space == 9 && layer == 3)
				{
					space = 6;
				}

				if (space == 12 && layer == 3)
				{
					space = 8;
				}

				card1 = rand() % 6 + 1;
			}

			if (space == 1 || space == 4 || space == 7 || space == 10 || space == 13)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a chance space. Pull a chance card.\n";

				if (space == 1)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 4)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 7)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 10)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 13)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				climb = 1;
				card1 = rand() % 6 + 1;
			}

			if (space == 2 || space == 5 || space == 8 || space == 11 || space == 14)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";

				layer--;

				if (space == 2)
				{
					space = 1;
				}

				if (space == 5)
				{
					space = 5;
				}

				if (space == 8)
				{
					space = 9;
				}

				if (space == 11)
				{
					space = 13;
				}

				if (space == 14)
				{
					space = 17;
				}

				climb = 3;
				card1 = rand() % 6 + 1;
			}

		}

		//if the player played card 2
		if (play == 2)
		{
			//adds the card number to the space number
			space = space + card2;

			if (space > 14)
			{
				space = (space - 15) + card2;
			}

			if (space == 0 || space == 3 || space == 6 || space == 9 || space == 2)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card2 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 0 && layer == 3)
				{
					space = 0;
				}

				if (space == 3 && layer == 3)
				{
					space = 2;
				}

				if (space == 6 && layer == 3)
				{
					space = 4;
				}

				if (space == 9 && layer == 3)
				{
					space = 6;
				}

				if (space == 12 && layer == 3)
				{
					space = 8;
				}

				card2 = rand() % 6 + 1;
			}

			if (space == 1 || space == 4 || space == 7 || space == 10 || space == 13)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a chance space. Pull a chance card.\n";

				if (space == 1)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 4)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 7)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 10)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 13)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				climb = 1;
				card2 = rand() % 6 + 1;
			}

			if (space == 2 || space == 5 || space == 8 || space == 11 || space == 14)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";

				layer--;

				if (space == 2)
				{
					space = 1;
				}

				if (space == 5)
				{
					space = 5;
				}

				if (space == 8)
				{
					space = 9;
				}

				if (space == 11)
				{
					space = 13;
				}

				if (space == 14)
				{
					space = 17;
				}

				climb = 3;
				card2 = rand() % 6 + 1;
			}

		}

		//if the player played card 3
		if (play == 3)
		{
			//adds the card number to the space number
			space = space + card3;

			if (space > 14)
			{
				space = (space - 15) + card3;
			}

			if (space == 0 || space == 3 || space == 6 || space == 9 || space == 2)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card3 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 0 && layer == 3)
				{
					space = 0;
				}

				if (space == 3 && layer == 3)
				{
					space = 2;
				}

				if (space == 6 && layer == 3)
				{
					space = 4;
				}

				if (space == 9 && layer == 3)
				{
					space = 6;
				}

				if (space == 12 && layer == 3)
				{
					space = 8;
				}

				card3 = rand() % 6 + 1;
			}

			if (space == 1 || space == 4 || space == 7 || space == 10 || space == 13)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a chance space. Pull a chance card.\n";

				if (space == 1)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 4)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 7)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 10)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (space == 13)
				{
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				climb = 1;
				card3 = rand() % 6 + 1;
			}

			if (space == 2 || space == 5 || space == 8 || space == 11 || space == 14)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";

				layer--;

				if (space == 2)
				{
					space = 1;
				}

				if (space == 5)
				{
					space = 5;
				}

				if (space == 8)
				{
					space = 9;
				}

				if (space == 11)
				{
					space = 13;
				}

				if (space == 14)
				{
					space = 17;
				}

				climb = 3;
				card3 = rand() % 6 + 1;
			}

		}
	}

	if (layer == 3)
	{
		//if the player played card 1
		if (play == 1)
		{
			//adds the card number to the space number
			space = space + card1;

			if (space > 9)
			{
				space = (space - 10) + card1;
			}

			if (space == 0 || space == 2 || space == 4 || space == 6 || space == 8)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card1 = rand() % 6 + 1;
				//displays the cards for the player to pick
				cout << "1: " << card1 << "\n";
				cout << "2: " << card2 << "\n";
				cout << "3: " << card3 << "\n";
				cin >> play;

				//checks to see if the card's value is 1
				if (play == 1 && card1 == 1)
				{
					std::cout << "You win!";
					layer++;
				}

				if (play == 2 && card2 == 1)
				{
					std::cout << "You win!";
					layer++;
				}

				if (play == 3 && card3 == 1)
				{
					std::cout << "You win!";
					layer++;
				}

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 2 spaces away from the climb space.\n";
				}

				card1 = rand() % 6 + 1;
			}

			if (space == 1 || space == 3 || space == 5 || space == 7 || space == 9)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";
				layer--;

				if (space == 1)
				{
					space = 13;
				}

				if (space == 4)
				{
					space = 1;
				}

				if (space == 7)
				{
					space = 4;
				}

				if (space == 10)
				{
					space = 7;
				}

				if (space == 13)
				{
					space = 10;
				}

				climb = 1;
				card1 = rand() % 6 + 1;
			}

		}

		//if the player played card 2
		if (play == 2)
		{
			//adds the card number to the space number
			space = space + card2;

			if (space > 14)
			{
				space = (space - 15) + card2;
			}

			if (space == 0 || space == 3 || space == 6 || space == 9 || space == 2)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card2 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 0 && layer == 3)
				{
					space = 0;
				}

				if (space == 3 && layer == 3)
				{
					space = 2;
				}

				if (space == 6 && layer == 3)
				{
					space = 4;
				}

				if (space == 9 && layer == 3)
				{
					space = 6;
				}

				if (space == 12 && layer == 3)
				{
					space = 8;
				}

				card2 = rand() % 6 + 1;
			}

			if (space == 1 || space == 3 || space == 5 || space == 7 || space == 9)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";
				layer--;

				if (space == 1)
				{
					space = 13;
				}

				if (space == 4)
				{
					space = 1;
				}

				if (space == 7)
				{
					space = 4;
				}

				if (space == 10)
				{
					space = 7;
				}

				if (space == 13)
				{
					space = 10;
				}

				climb = 1;
				card1 = rand() % 6 + 1;
			}

		}

		//if the player played card 3
		if (play == 3)
		{
			//adds the card number to the space number
			space = space + card3;

			if (space > 14)
			{
				space = (space - 15) + card3;
			}

			if (space == 0 || space == 3 || space == 6 || space == 9 || space == 2)
			{
				//tells the system that the player is on a climb space
				climb = 0;

				//tells player where they landed and what happens
				std::cout << "You have landed on a climb space. You must now pick up a chance card and play a 1 to go up to layer 3.\n";

				card3 = rand() % 6 + 1;
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

				if (play == 1 && card1 != 1)
				{
					//makes the player not move
					card1 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 2 && card2 != 1)
				{
					//makes the player not move
					card2 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				if (play == 3 && card3 != 1)
				{
					//makes the player not move
					card3 = 0;

					//tells the player that they cannot climb
					std::cout << "You cannot climb the to the next layer yet.\n\n";

					//tells the user how far they are from the next climb space
					std::cout << "You are 3 spaces away from the climb space.\n";
				}

				//makes the space value correspond with the space value on the next layer
				if (space == 0 && layer == 3)
				{
					space = 0;
				}

				if (space == 3 && layer == 3)
				{
					space = 2;
				}

				if (space == 6 && layer == 3)
				{
					space = 4;
				}

				if (space == 9 && layer == 3)
				{
					space = 6;
				}

				if (space == 12 && layer == 3)
				{
					space = 8;
				}

				card3 = rand() % 6 + 1;
			}

			if (space == 1 || space == 3 || space == 5 || space == 7 || space == 9)
			{
				//tells player where they landed and what happens
				std::cout << "You have landed on a red space. You have gone back 3 spaces.\n";
				layer--;

				if (space == 1)
				{
					space = 13;
				}

				if (space == 4)
				{
					space = 1;
				}

				if (space == 7)
				{
					space = 4;
				}

				if (space == 10)
				{
					space = 7;
				}

				if (space == 13)
				{
					space = 10;
				}

				climb = 1;
				card1 = rand() % 6 + 1;
			}

		}
	}

	return space;
}