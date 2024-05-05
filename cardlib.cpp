// RJM's file for getting a random card
// 6/2/24
#include <iostream>
#include <string>
#include <vector>
#include "cardlib.h"
using namespace std;

string cardToStr(aCard c) {
    // Define strings to represent suits
    string csuit = "HDCS";

    // Ensure cardSuit is within the valid range
    int suitIndex = static_cast<int>(c.cardSuit); // Convert enum to int
    if (suitIndex < 0 || suitIndex >= csuit.size()) {
        // Handle invalid cardSuit value
        return "Invalid Suit";
    }

    // Get character for suit
    char suit = csuit[suitIndex];

    // Get character for the card value
    char valueChar;
    if (c.cardVal > 1 && c.cardVal < 10) {
        // For cards 1-9, convert integer to character
        valueChar = c.cardVal + '0';
    }
    else {
        // Get valueChar for special cards e.g Ace
        switch (c.cardVal) {
        case 1:
            valueChar = '1';
            break;
        case 10:
            valueChar = 'T';
            break;
        case 11:
            valueChar = 'J';
            break;
        case 12:
            valueChar = 'Q';
            break;
        case 13:
            valueChar = 'K';
            break;
        default:
            // Handle invalid card value
            return "Invalid Card Value";
        }
    }

    // Constructor for a string of length 1 for 1 instance of valueChar
    return string(1, valueChar) + suit;
}


// Function to print the pack of cards
void printPack(string mess, aCard thePack[]) {
    // Maximum number of cards to print
    const int maxCard = 20;
// Print message and the first maxCard cards in the pack
    cout << mess << " : ";
    // for loop to print the first maxCard cards
    for (int i = 0; i < maxCard; ++i) {
        cout << cardToStr(thePack[i]);
        //if statement to print a comma after all but the last card
        if (i != maxCard - 1) {
            cout << ", ";
        }
    }
    cout << std::endl;
}
// Function to get a random card
aCard getCard(string stdno) {
    // Answer card
    aCard ans;
    // Generate two random characters from student number
    string randomChars = stdno.substr(rand() % 8, 1) + stdno.substr(rand() % 8, 1);
    // Convert random chars to an integer in range 0-51
    int rcard = stoi(randomChars) % 52;
    // Determine cardVal and cardSuit based on rcard
    // Card value in the range 1-13
    ans.cardVal = 1 + rcard % 13;
    // Card suit based on rcard
    ans.cardSuit = static_cast<Suit>(rcard / 13);
    // Debugging output
   // cout << "Generated card: Value = " << ans.cardVal << ", Suit = " << ans.cardSuit << endl;
    return ans;
}

/*
int compareCards(aCard c1, aCard c2) {
    int comparisonCount = 0; // Counter for comparisons
     comparisonCount++; // Increment comparison count
    // Compare two cards, c1 and c2
    // Return -1 (c1 < c2), 0 (c1 == c2), 1 (c1 > c2)
    // Sort cards by suit as the first key and number as the second key
    // Compare suits
    if (c1.cardSuit < c2.cardSuit) {
        return -1;
    }
    else if (c1.cardSuit > c2.cardSuit) {
        return 1;
    }

    // If suits are equal, compare card values
    if (c1.cardVal < c2.cardVal) {
        return -1;
    }
    else if (c1.cardVal > c2.cardVal) {
        return 1;
    }

    // If both suit and value are equal, return 0
    return 0;
}

void swapCards(aCard thePack[], int n1, int n2) {
    int movementCount = 0;   // Counter for movements
    movementCount++; // Increment movement count
    // Swap the cards in thePack at indices n1 and n2
    aCard temp = thePack[n1];
    thePack[n1] = thePack[n2];
    thePack[n2] = temp;
}*/

void bubbleSort(aCard thePack[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // Compare adjacent cards and swap if necessary
            if (compareCards(thePack[j], thePack[j + 1]) > 0) {
                swapCards(thePack, j, j + 1);
            }
        }
    }
}


