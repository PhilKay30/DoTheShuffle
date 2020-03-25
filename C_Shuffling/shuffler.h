// File: shuffler.h
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains includes and prototypes for shuffler.c

#pragma once

// function for shuffling a list
void shuffle(char* strArray, int numOfElement, int sizeOfElement, int (*randFunc)());