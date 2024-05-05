#pragma once



// header file for cardlib
// RJM 06/01/24


#include <string>
using namespace std;

enum Suit { hearts, clubs, diamonds, spades };      // define suits

struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string cardToStr(aCard c);			// declare function to represent a card as a two character string

aCard getCard(std::string stdno);        // declares function to get a card from stdno str

void printPack(string mess, aCard thePack[]); // declares function to print the pack of cards

int compareCards(aCard c1, aCard c2); // Declare function to compare two cards

void swapCards(aCard thePack[], int n1, int n2); // Declare function to swap two cards in the pack

void bubbleSort(aCard thePack[], int size); // Declare function to sort the pack of cards using bubble sort


