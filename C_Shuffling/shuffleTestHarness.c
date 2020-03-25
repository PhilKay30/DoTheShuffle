// File: shuffleTestHarness.c
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains methods for performing a user controlled test of a shuffling algorithm using a "deck of cards"

#include "shuffleTestHarness.h"

// Name: runShufflingTest
// Description: Allows a user to continuously shuffle and display a deck of cards
// Parameters: 
//		myAppContext: contextual info that holds the rand function for shuffling
// Returns: n/a
void runShufflingTest(appContext myAppContext)
{
	// define user options for the running loop
	char options[MAX_OPTIONS][MAX_OPTION_LEN] = {
		"New Deck",
		"Shuffle",
		"Exit"
	};

	// create our deck of cards
	deck d = newDeck();

	// loop continuously until user decides to finish
	bool isRunning = true;
	while (isRunning)
	{
		// clear the screen of any previous data, display any error messages, and display the deck
		clearScreen();
		displayDeck(d);

		// let user choose what option they'd like to do for the test
		int selection = getOptionSelection(options, 3);
		switch (selection)
		{
		case 1:
			// 1. New Deck
			d = newDeck();
			break;
		case 2:
			// 2. Shuffle
			shuffleDeck(&d, myAppContext.randFunc);
			break;
		case 3:
			// 3. Exit
			isRunning = false;
			break;
		default:
			// Error, should never happen
			// Intentionally do nothing here
			break;
		}
	}
}

// Name: displayDeck
// Description: Display the contents of a deck to the user
// Parameters: 
//		d:	the deck to display
// Returns: n/a
void displayDeck(deck d)
{
	displayMessage(deckToString(d));
}