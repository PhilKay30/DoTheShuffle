// File: consoleIO.h
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains header includes, constants, and prototypes for consolIO.c

#pragma once
#include <stdio.h>

// constants for max option count and length
#define MAX_OPTIONS 10
#define MAX_OPTION_LEN 30

// constant for converting a char to it's int representation ('1' becomes 1)
#define INT_TO_CHAR_OFFSET 48

// constant for defining max length for messages to the user
#define MAX_MSG_LEN 100

// function for getting user's selection of a number of options
int getOptionSelection(char options[MAX_OPTIONS][MAX_OPTION_LEN], int numOptions);

// function for clearing the console
void clearScreen();

// function for displaying a message to the user
void displayMessage(char msg[MAX_MSG_LEN]);