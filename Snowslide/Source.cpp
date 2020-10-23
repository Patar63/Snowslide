#include <iostream>
#include <string>
using namespace std;

char input;

int main()
{
	string enterPressed;
	int climb = 5;
	int layer = 1;

	cout << "You are a new hiker, determined to climb the mountain in front of you. Good luck, and be careful of snowslides.\n";
	cout << "Press Enter to start...\n";
	getline(cin, enterPressed);

	if (enterPressed.empty())
	{
		cout << "Enter was pressed\n";
	}
	else
	{
		cout << "A letter was entered with enter\n";
	}
}