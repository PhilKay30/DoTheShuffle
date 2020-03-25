// File: appContext.h
// Programmer: Philip Kempton
// First Version: March 24th, 2020
// Decription: Contains a struct to actas the application's context

#pragma once

// This struct holds contextual stuff for this application
typedef struct AppContext
{
	// This function pointer acts as a rand function
	int (*randFunc)(int minBound, int maxBound);
} appContext;