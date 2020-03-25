// File: shuffleTestHarness.h
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains header includes and prototypes for shuffleTestHarness.c

#pragma once
#include "consoleIO.h"
#include "deck.h"
#include "appContext.h"

// function for the testing loop
void runShufflingTest(appContext myAppContext);

// function to display a deck to the user
void displayDeck(deck d);