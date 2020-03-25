// File: deck.c
// Programmer: Philip Kempton
// First Version: 2020-03-25
// Description: This file contains methods for manipulating a deck of cards (char array of 52 chars)

#include "deck.h"

// Name: newDeck
// Description: sets a deck of cards to "new" order (char array of chars from 0-51)
// Parameters:
//		deck:	pointer to the char array
// Returns: void
void newDeck(char* deck)
{
	// assign the deck elements to 0-51
    for (char i = 0; i < DECK_SIZE; i++)
    {
		// set value, then perform pointer increment to point at next char
        *deck++ = i;
    }
}

// Name: shuffleDeck
// Description: randomly shuffles a deck of cards (char[52])
// Parameters:
//		deck:	pointer to the char array
// Returns: void
void shuffleDeck(char* deck)
{
	fisherYatesShuffle(deck, DECK_SIZE, sizeof(char));
}

// Name: fisherYatesShuffle
// Description: shuffles an array of elements using the Fisher-Yates algorithm
// CODE REFERENCE: 
//		Durstenfeld, R (1964). Fisher-Yates Shuffle [algorithm]. Retrieved on  March 23rd, 2020 from 
//		https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
// Parameters:
//		arrayPtr:		pointer to the array to shuffle
//		numOfElements:	number of elements in the array
// Returns: void
void fisherYatesShuffle(char* arrayPtr, int numOfElements, int sizeOfElement)
{
	// loop through each element, end to first, swapping it with a random element before it in the array
	for (int elementIndex = numOfElements - 1; elementIndex > 0; elementIndex--)
	{
		int randElement = rand() % elementIndex;
		for (int i = 0; i < sizeOfElement; i++)
		{
			// get pointers to the 2 elements to swap
			char* elementToSwapPtr = arrayPtr + elementIndex * sizeOfElement + i;
			char* randEelementPtr = arrayPtr + randElement * sizeOfElement + i;

			// swap the elements using a temp variable
			char buff = *elementToSwapPtr;
			*elementToSwapPtr = *randEelementPtr;
			*randEelementPtr = buff;
		}
	}
}