// ITP 365 Fall 2015
// HW1 - Sieve of Eratosthenes
// Name: Johnathan Mai
// Email: johnathm@usc.edu
// Platform: Mac

#pragma once
#include "gwindow.h"

enum NumberType {
    UNKNOWN,
    PRIME,
    COMPOSITE,
};

// Function: drawSquare
// Purpose: Draws a square in the given GWindow with the given number in the center and colored corresponding to the number type provided at the location provided.
// Input: A GWindow passed by reference, an int for the display number, a number type, and two doubles for coordinates.
// Output: Draws a square in the given GWindow. No physical output.
void drawSquare(GWindow &mainScreen, int displayNumber, NumberType type, double topLeftX, double topLeftY);

// Function: initVectors
// Purpose: Initializes the numbers and numberTypes vectors to a vector of 2 - 101 and corresponding number type UNKNOWN for all of them.
// Input: Two vectors, one to hold the numbers that will be the displays and one to hold their number types.
// Output: Initializes them, no physical output.
void initVectors(Vector<int> &numbers, Vector<NumberType> &numberTypes);

// Function: drawGrid
// Purpose: Draws the grid that we will be using, from the numbers vector.
// Input: a GWindow, a numbers vector, and a number types vector that corresponds with the number vector
// Output: 
void drawGrid(GWindow &mainScreen, Vector<int> &numbers, Vector<NumberType> &numberTypes);

// Function: calcNextPrime
// Purpose: Calculates the next prime number, sets that number to PRIME, and sets all of its multiples that exist in the numbers vector to COMPOSITE
// Input: The numbers and numberTypes vectors and a starting index
// Output: Sets multiples of the prime number to COMPOSITE, the number to PRIME, and returns the prime number.
int calcNextPrime(Vector<int> &numbers, Vector<NumberType> &numberTypes, int startAt);
