// File: shuffler.c
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains a method for randomly shuffling an array

#include "shuffler.h"

// Name: shuffle
// Description: shuffles the elements of an array using a randomization function
// Parameters:
//		arrayPtr:		pointer of the array to shuffle
//		numOfElements:	number of elements in the array
//		sizeOfElement:	size, in bytes, of each element
//		*randFunc:		randomization function to use
// Returns: n/a
void shuffle(char* arrayPtr, int numOfElements, int sizeOfElement, int (*randFunc)())
{
	// This method implements the Fisher-Yates shuffle algorithm
	// CODE REFERENCE: 
	//		Durstenfeld, R (1964). Fisher-Yates Shuffle [algorithm]. Retrieved on 
    //      March 23rd, 2020 from https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	for (int elementToSwap = numOfElements - 1; elementToSwap > 0; elementToSwap--)
	{
		int randElement = randFunc() % elementToSwap;
		for (int i = 0; i < sizeOfElement; i++)
		{
			char* lPtr = arrayPtr + elementToSwap * sizeOfElement + i;
			char* rPtr = arrayPtr + randElement * sizeOfElement + i;
			char buff = *lPtr;
			*lPtr = *rPtr;
			*rPtr = buff;
		}
	}
}