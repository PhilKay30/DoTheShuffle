// File: deck.h
// Programmer: Philip Kempton
// First Version: 2020-03-25
// Description: This file contains library includes, constants, and prototypes for deck.c

#pragma once

// library includes
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// define number of suits in the deck and number of card names in the deck (Ace->King)
#define NUM_OF_SUITS 4
#define NUM_OF_NAMES 13

// define strings lengths for max suit length and max card name length
#define MAX_SUIT_STR_LEN 9
#define MAX_NAME_STR_LEN 6

// define number of cards in a deck
#define DECK_SIZE 52

// define card suits
const static char suits[NUM_OF_SUITS][MAX_SUIT_STR_LEN] = {
    "Spades", "Hearts", "Diamonds", "Clubs"
};

// define card names
const static char cardNames[NUM_OF_NAMES][MAX_NAME_STR_LEN] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

// prototypes
void newDeck(char* deck); // in deck.c
void shuffleDeck(char* deck); // in deck.c
void fisherYatesShuffle(char* arrayPtr, int numOfElements, int sizeOfElement); // in deck.c
