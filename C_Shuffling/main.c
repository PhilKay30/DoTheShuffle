// File: main.c
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains main() for this application.

#include "main.h"

// Name: main
// Description: main() for this console app.
//              This application uses a "deck of cards" to test a shuffling algorithm.
// Parameters: n/a
// Returns: 0
int main()
{
    // seed rand with time and set it as the function to be used for randomized shuffling
    time_t t;
    srand((unsigned)time(&t));
    appContext myAppContext;
    myAppContext.randFunc = rand;

    // start the test harness, exiting after its' completion
    runShufflingTest(myAppContext);
    return 0;
}