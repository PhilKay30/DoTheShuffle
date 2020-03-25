// File: consoleIO.c
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains functions that act as an interface to the console, using it as a UI

#include "consoleIO.h"

// Name: getOptionSelection
// Description: Get's the user's choice between a number of options
// Parameters: 
//		options:	the array of options for the user to choose
//		numOptions:	the number of options to lets the user choose between
// Returns: user selection (1 indexed)
int getOptionSelection(char options[MAX_OPTIONS][MAX_OPTION_LEN], int numOptions)
{
	// display all options to user
	fprintf(stdout, "Please Select an Option\n");
	for (int i = 0; i < numOptions; i++)
	{
		fprintf(stdout, "%d. %s\n", i + 1, options[i]);
	}

	// get user selection repeatedly until its' valid, then return it
	int selection = 0;
	while (selection < 1)
	{
		char buff = getch();
		if (buff >= '1' && buff <= (numOptions + INT_TO_CHAR_OFFSET))
		{
			selection = buff - INT_TO_CHAR_OFFSET;
		}
	}
	return selection;
}

// Name: clearScreen
// Description: Clears the console
// Parameters: n/a
// Returns: n/a
void clearScreen()
{
	system("cls");
}

// Name: displayMessage
// Description: Display's a message to the user
// Parameters: 
//		msg:	the message to display to the user
// Returns: n/a
void displayMessage(char msg[MAX_MSG_LEN])
{
	fprintf(stdout, "%s\n\n", msg);
}