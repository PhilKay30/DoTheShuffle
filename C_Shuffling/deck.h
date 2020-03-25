// File: deck.h
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains header includes, constants, prototypes, and a struct for deck.c

#pragma once
#include "shuffler.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Constant for size of deck and number of suits / values
#define DECK_SIZE 52
#define SUIT_COUNT 4
#define VALUE_COUNT 13

// Constants for max string lengths for char arrays for a card
#define MAX_SUIT_LEN 10
#define MAX_VALUE_LEN 10
#define CARD_STR_LEN 30

// This struct represnts a deck of cards
typedef struct Deck
{
	// The array of cards (stored in chars from 0-51)
	char cards[52];
} deck;

// Function to get char* representation of a deck
char* deckToString(deck d);

// Function to shuffle a deck
void shuffleDeck(deck* d, int (*randFunc)());

// Function to get a new, ordered deck
deck newDeck();

