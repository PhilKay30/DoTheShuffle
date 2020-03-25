// File: main.c
// Programmer: Philip Kempton
// First Version: 2020-03-24
// Description: This file contains main() for this application.
//              This application implements the shuffling of a deck of cards using the Fisher-Yates Shuffle alogrithm.
// References: This application was changed on March 25th, 2020 based on a code review done by Mark Paruzel (https://github.com/mparuzel).

#include "deck.h"

// Name: main
// Description: starting point for this application
// Parameters: none
// Returns: 0
int main()
{
    // create the deck of cards
    char deck[DECK_SIZE] = { 0 };
    newDeck(deck);

    // enter input/output loop (exits only when user chooses the EXIT option)
    while (1)
    {
        // clear the console and display each card in the deck to show current order
        system("cls");
        for (int cardIndex= 0; cardIndex < DECK_SIZE; cardIndex++)
        {
            // modulo and division are used to convert the char (0-51) into a specific card
            printf("%s of %s\n", cardNames[deck[cardIndex] % NUM_OF_NAMES], suits[deck[cardIndex] / NUM_OF_NAMES]);
        }

        // present options to user
        printf("\nSelect an Option:\n");
        printf("1. New Deck\n");
        printf("2. Shuffle\n");
        printf("3. Exit\n");

        // repeatedly get input, char by char, from the user until they choose a valid action, then perform the action
        bool inputIsValid = false;
        while (!inputIsValid)
        {
            char inputBuff = _getch();
            switch (inputBuff)
            {
            case '1': // New Deck option
                inputIsValid = true;
                newDeck(deck);
                break;
            case '2': // Shuffle option
                inputIsValid = true;
                shuffleDeck(deck);
                break;
            case '3': // Exit option
                return 0;
            }
        }
    }
}
