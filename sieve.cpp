
#include "sieve.h"
#include <string>

void drawSquare(GWindow &mainScreen, int displayNumber, NumberType type, double topLeftX, double topLeftY) {
    std::string color = "";
    
    // Switch statement to correspond color to numberType
    switch (type) {
        case UNKNOWN:
            color = "white";
            break;
        case PRIME:
            color = "green";
            break;
        case COMPOSITE:
            color = "red";
            break;
        default:
            break;
    }
    mainScreen.setColor(color);
    mainScreen.fillRect(topLeftX, topLeftY, 50, 50);
    mainScreen.setColor("black");
    mainScreen.drawLabel(std::to_string(displayNumber), topLeftX + 25, topLeftY + 25);
    mainScreen.drawRect(topLeftX, topLeftY, 50, 50);
}


void initVectors(Vector<int> &numbers, Vector<NumberType> &numberTypes) {
    for (int i = 2; i < 102; i++) {
        numbers.push_back(i);
        numberTypes.push_back(UNKNOWN);
    }
}


void drawGrid(GWindow &mainScreen, Vector<int> &numbers, Vector<NumberType> &numberTypes) {
    if (numbers.size() != numberTypes.size()) {
        std::cout << "Error, your numbers vector doesn't match your numberTypes vector." << std::endl;
        exit(EXIT_FAILURE); // prevents creating a grid if your numbers and numberTypes vector don't match up
    }
    int x = 0;
    int y = 0;
    
    // Loop to draw all squares
    for (int i = 0; i < numbers.size(); i++) {
        drawSquare(mainScreen, numbers[i], numberTypes[i], x, y);
        x += 50;
        if (x == 500) {
            y += 50;
            x = 0;
        }
        else {
            continue;
        }
    }
    
}


int calcNextPrime(Vector<int> &numbers, Vector<NumberType> &numberTypes, int startAt) {
    
    // Check to see if startAt is at the end of the vector first
    if (startAt > numberTypes.size()) {
        return -1;
    }
    
    // Otherwise, commence function!!

    // Finding next index with UNKNOWN as a number type:
    for (int i = startAt; i < numberTypes.size(); i++) {
        if (numberTypes[i] == UNKNOWN)
        {
            numberTypes[i] = PRIME;
            
            // Divides every number by the number we just set as prime, if it gives no remainder then set as composite
            for (int j = i+1; j < numbers.size(); j++) {
                int remainder = 0;
                remainder = numbers[j] % numbers[i];
                if (remainder == 0) {
                    numberTypes[j] = COMPOSITE;
                }
                else {
                    continue;
                }
            }
            return numbers[i]; // returning just-determined prime number
        }
        else {
            continue;
        }
    }
    return -1;
}