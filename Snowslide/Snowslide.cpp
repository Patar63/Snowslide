#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>


void gameStart();
void playerInfo();

void playerIntroduction();
void cardSelection(int& playerMovement);
void ropeSelection(int& playerMovement, int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces);
void increaseLevel(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces);
void decreaseLevel(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces);
void snowslideChance(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces);
void gameEnd();

void snowslideChance(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces)
{
	srand(time(NULL));
	int chanceCard = rand() % 4 + 1;



	switch (chanceCard) {
		case 1:
			std::cout << "\n";
			std::cout << "Oh No! A snowslide has occurred!";

			if (mountainLayer == 0) 
			{
				std::cout << "\n";
				std::cout << "Thankfully your at the bottom of the mountain and it doesn't reach you!\n";
				std::cout << "\n";
			}
			else if (mountainLayer == 1) 
			{
				std::cout << "\n";
				std::cout << "Due to the snowslide you have fallen down a level of the mountain!\n";
				std::cout << "\n";
				decreaseLevel(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
				
			}
			else if (mountainLayer == 2) 
			{
				std::cout << "\n";
				std::cout << "Due to the snowslide you have fallen down a level of the mountain!\n";
				std::cout << "\n";
				decreaseLevel(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
			}
		


	}
}

void increaseLevel(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces) 
{
	if (mountainLayer == 0) {

		
		totalPlayerMovement = 0;
		mountainLayer = mountainLayer + 1;
		rope1 = 4;
		rope2 = 8;
		rope3 = 12;
		rope4 = 16;
		rope5 = 20;
		std::cout << "Your path grows steeper!\n";
		std::cout << "You have made it to mountain layer " << mountainLayer << ".\n";
	}
	else if (mountainLayer == 1) 
	{

		totalPlayerMovement = 0;
		mountainLayer = mountainLayer + 1;
		rope1 = 3;
		rope2 = 6;
		rope3 = 9;
		rope4 = 12;
		rope5 = 15;

	}
	else if (mountainLayer == 2) 
	{
		gameEnd();
	}

}

void decreaseLevel(int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces) 
{
	if (mountainLayer == 1) {

		totalPlayerMovement = 0;
		mountainLayer = mountainLayer - 1;
		rope1 = 5;
		rope2 = 10;
		rope3 = 15;
		rope4 = 20;
		rope5 = 25;

	}
	else if (mountainLayer == 2)
	{

		totalPlayerMovement = 0;
		mountainLayer = mountainLayer - 1;
		rope1 = 4;
		rope2 = 8;
		rope3 = 12;
		rope4 = 16;
		rope5 = 20;

	}
}

void gameEnd() 
{
	std::cout << "   _____                                          _         \n";
	std::cout << "  / ____|                                        | |        \n";
	std::cout << " | |        ___    _ __     __ _   _ __    __ _  | |_   ___ \n";
	std::cout << " | |       / _ \\  | '_ \\   / _` | | '__|  / _` | | __| / __|\n";
	std::cout << " | |____  | (_) | | | | | | (_| | | |    | (_| | | |_  \\__ \\\n";
	std::cout << "  \\_____|  \\___/  |_| |_|  \\__, | |_|     \\__,_|  \\__| |___/\n";
	std::cout << "                            __/ |                           \n";
	std::cout << "                           |___/                            \n";

	exit(0);
}

void ropeSelection(int& playerMovement, int& mountainLayer, int& rope1, int& rope2, int& rope3, int& rope4, int& rope5, int& totalPlayerMovement, int& totalSpaces)
{
	srand(time(NULL));
	int playerRoll1 = rand() % 6 + 1;
	int playerRoll2 = rand() % 6 + 1;
	int playerRoll3 = rand() % 6 + 1;
	int playerSelection = 0;
	bool correctSelection = false;

	while (correctSelection == false) {

		std::cout << "How far would you like to move: \n";
		std::cout << "1: " << playerRoll1 << "\n";
		std::cout << "2: " << playerRoll2 << "\n";
		std::cout << "3: " << playerRoll3 << "\n";
		std::cin >> playerSelection;
		std::cout << "\n";

		if (playerSelection == 1 && playerRoll1 == 1)
		{
			std::cout << "You have ascended the mountain!\n";
			increaseLevel(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
			correctSelection = true;
			
		}
		else if (playerSelection == 2 && playerRoll2 == 1)
		{
			std::cout << "You have ascended the mountain!\n";
			increaseLevel(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
			correctSelection = true;
			
		}
		else if (playerSelection == 3 && playerRoll3 == 1)
		{
			std::cout << "You have ascended the mountain!\n";
			increaseLevel(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
			correctSelection = true;
			
		}
		else if (playerSelection == 1  && playerRoll1 != 1) 
		{
			std::cout << "Sorry but you did not manage to climb the rope!\n";
			correctSelection = true;
		}
		else if (playerSelection == 2 && playerRoll1 != 1)
		{
			std::cout << "Sorry but you did not manage to climb the rope!\n";
			correctSelection = true;
		}
		else if (playerSelection == 3 && playerRoll1 != 1)
		{
			std::cout << "Sorry but you did not manage to climb the rope!\n";
			correctSelection = true;
		}
		else
		{
			std::cout << "That is not a valid selection\n";
		}
	}
}


void cardSelection(int& playerMovement) 
{
	srand(time(NULL));
	int playerRoll1 = rand() % 6 + 1;
	int playerRoll2 = rand() % 6 + 1;
	int playerRoll3 = rand() % 6 + 1;
	int playerSelection = 0;
	bool correctSelection = false;

	while (correctSelection == false) {

		std::cout << "How far would you like to move: \n";
		std::cout << "1: " << playerRoll1 << "\n";
		std::cout << "2: " << playerRoll2 << "\n";
		std::cout << "3: " << playerRoll3 << "\n";
		std::cin >> playerSelection;
		std::cout << "\n";

		if (playerSelection == 1)
		{
			playerMovement = playerRoll1;
			correctSelection = true;
		}
		else if (playerSelection == 2)
		{
			playerMovement = playerRoll2;
			correctSelection = true;
		}
		else if (playerSelection == 3)
		{
			playerMovement = playerRoll3;
			correctSelection = true;
		}
		else
		{
			std::cout << "That is not a valid selection\n";
		}
	}
}



void gameStart() 
{
	
	bool gameStrt = true;
	int mountainLayer = 0;
	int mountainSpace = 0;
	int playerMovement = 0;
	int totalPlayerMovement = 0;
	int totalSpaces = 20;

	int rope1 = 5;
	int rope2 = 10;
	int rope3 = 15;
	int rope4 = 20;
	int rope5 = 25;

	while (gameStrt == true) 
	{

		if (totalPlayerMovement >= totalSpaces) {
			totalPlayerMovement = totalPlayerMovement - totalSpaces;
			std::cout << "You have looped the mountain! Start mathing out the ropes!\n";
		}

		cardSelection(playerMovement);
		snowslideChance(mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
		
		totalPlayerMovement += playerMovement;
		std::cout << "You have moved "<< playerMovement << " spaces!\n";
		std::cout << "Your total movement is " << totalPlayerMovement << "\n";
		
		


		
		if (totalPlayerMovement == rope1)
		{
			std::cout << "\nYou have reached rope 1! If you select a 1 you may advance up the mountain!\n";
			ropeSelection(playerMovement, mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
			
		}
		else if (totalPlayerMovement == rope2)
		{
			std::cout << "\nYou have reached rope 2! If you select a 1 you may advance up the mountain!\n";
			ropeSelection(playerMovement, mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
		}
		else if (totalPlayerMovement == rope3)
		{
			std::cout << "\nYou have reached rope 3! If you select a 1 you may advance up the mountain!\n";
			ropeSelection(playerMovement, mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
		}
		else if (totalPlayerMovement == rope4)
		{
			std::cout << "\nYou have reached rope 4! If you select a 1 you may advance up the mountain!\n";
			ropeSelection(playerMovement, mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
		}
		else if (totalPlayerMovement == rope5)
		{
			std::cout << "\nYou have reached rope 5! If you select a 1 you may advance up the mountain!\n";
			ropeSelection(playerMovement, mountainLayer, rope1, rope2, rope3, rope4, rope5, totalPlayerMovement, totalSpaces);
		}


	}

}

void playerInfo() 
{
	char playGame;

	std::cout << "\n";
	std::cout << "Your goal as a hiker is to climb the different levels of Mount Sohcahtoa!\n";
	std::cout << "On each corner of the mountain is the climb space/climb rope. When you first cross the rope space\n";
	std::cout << "You are stuck on the space as you attempt to climb the space, until you roll a 1 you cannot climb the rope.\n";
	std::cout << "Would you like to begin playing? Y or N:\n";
	std::cin >> playGame;

	if (playGame == 'Y') 
	{
		gameStart();
	}
	else
	{
		std::cout << "Thank you for reading! Be sure to play again when you would like to!";
		exit(0);
	}


}




void playerIntroduction() 
{
	char playerInformation;
	std::cout << "   _____                                    _   _       _       \n";
	std::cout << "  / ____|                                  | | (_)     | |       \n";
	std::cout << " | (___    _ __     ___   __      __  ___  | |  _    __| |   ___ \n";
	std::cout << "  \\___ \\  | '_ \\   / _ \\  \\ \\ /\\ / / / __| | | | |  / _` |  / _ \\\n";
	std::cout << "  ____) | | | | | | (_) |  \\ V  V /  \\__ \\ | | | | | (_| | |  __/\n";
	std::cout << " |_____/  |_| |_|  \\___/    \\_/\\_/   |___/ |_| |_|  \\__,_|  \\___|\n";

	

	std::cout << "Welcome to Snowslide! You are a fresh hiker attempting to climb Mount Sohcahtoa!\n";
	std::cout << "Watch out for dangers and most importantly, be careful of Snowslides!\n";
	std::cout << "Would you like to learn about how to play? Y or N\n";
	std::cin >> playerInformation;

		if (playerInformation == 'Y') 
		{
			playerInfo();
		}
		else 
		{
			gameStart();
		}

}






int main()
{
	playerIntroduction();
}