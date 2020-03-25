// File: deck.c
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains Main() for this application.

#include "deck.h"

// Name: deckToString
// Description: This function builds and returns a string representation of a deck
// Parameters: 
//		d:	the deck
// Returns: string of all cards in the deck
char* deckToString(deck d)
{
	// Define card suits
	char suits[SUIT_COUNT][MAX_SUIT_LEN] = {
		"Spades", "Hearts", "Diamonds", "Clubs"
	};

	// Define card names
	char cardNames[VALUE_COUNT][MAX_VALUE_LEN] = {
		"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
	};

	// Define string to store string representation of the deck
	char deckStr[DECK_SIZE * CARD_STR_LEN] = { 0 };

	// Define string to store string representation of a card
	char cardStr[CARD_STR_LEN] = { 0 };

	// Loop through each "card" in the deck, turning it into its' string representation and concatenating it to the deck string
	// This is done with modulo and division to turn each char value (0-51) in a specific card
	for (int i = 0; i < DECK_SIZE; i++)
	{
		int valueIndex = d.cards[i] % VALUE_COUNT;
		int suitIndex = d.cards[i] / VALUE_COUNT;
		sprintf_s(cardStr, CARD_STR_LEN, "%s of %s\n", cardNames[valueIndex], suits[suitIndex]);
		strncat_s(deckStr, DECK_SIZE * CARD_STR_LEN, cardStr, strlen(cardStr));
	}
	return deckStr;
}

// Name: newDeck
// Description: Builds and returns a deck, ordered deck
// Parameters: n/a
// Returns: new deck
deck newDeck()
{
	// assign each "card" with a unique value, from 0-51 (to represent the different cards)
	deck d;
	for (int i = 0; i < DECK_SIZE; i++)
	{
		d.cards[i] = i;
	}
	return d;
}

// Name: newDeck
// Description: Shuffles a deck using a randomization function
// Parameters: 
//		d:			the deck to shuffle
//		randFunc:	function pointer to a rand function
// Returns: n/a
void shuffleDeck(deck* d, int (*randFunc)())
{
	shuffle(d->cards, DECK_SIZE, sizeof(char), randFunc);
}