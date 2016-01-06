
#include "gwindow.h"
#include "vector.h"
#include "sieve.h"
#include <iostream>
#include <string>


int main()
{
    // Variables
	GWindow gw(501, 501); // 501 to fit the borders on the bottom boxes heh
    Vector<int> numbers;
    Vector<NumberType> numberTypes;

	// TODO: Implement stuff
    
    // Initialize vectors and draw blank grid
    initVectors(numbers, numberTypes);
    drawGrid(gw, numbers, numberTypes);
    
    // Loop through all prime numbers and update grid after every prime number is determined
    int loopCondition = 0;
    int loopIndex = 0;
    while (loopCondition != -1) {
        loopCondition = calcNextPrime(numbers, numberTypes, loopIndex);
        loopIndex ++;
        pause(1000.0);
        drawGrid(gw, numbers, numberTypes);
    }
	return 0;
}
