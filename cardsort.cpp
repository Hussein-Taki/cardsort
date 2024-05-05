/// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// RJM 6/2/24

#include "cardlib.h"
#include <string>
#include <iostream>
using namespace std;


//global variables
const int maxCard = 20;
int comparisonCount = 0; // Counter for comparisons
int movementCount = 0;   // Counter for movements
int maxRecursionLevel = 0; // Counter for maximum recursion level


//functions to sort the pack of cards
//function to compare card values and suits
int compareCards(aCard c1, aCard c2) {
     // Counter for comparisons
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

//function to swap two cards in the pack
void swapCards(aCard thePack[], int n1, int n2) {
    movementCount++; // Increment movement count
    // Swap the cards in thePack at indices n1 and n2
    aCard temp = thePack[n1];
    thePack[n1] = thePack[n2];
    thePack[n2] = temp;
}






/*
//bubble sort function but i think it should be 190 not 191
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare an array to hold the pack of cards
    aCard thePack[maxCard];



    // Populate the pack of cards
    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("32006140"); // student number

    // Print the unsorted pack
    cout << "Card Sorting!\n";
    printPack("Unsorted", thePack);
    // Create two cards to compare
    aCard card1 = getCard("32006140");
    aCard card2 = getCard("32006140");


   
   // Compare the two cards
    int comparisonResult = compareCards(card1, card2);

    // Output the comparison result
    if (comparisonResult < 0) {
        cout << "Card 1 is less than Card 2" << endl;
    }
    else if (comparisonResult > 0) {
        cout << "Card 1 is greater than Card 2" << endl;
    }
    else {
        cout << "Card 1 is equal to Card 2" << endl;
    }


    // Swap two cards at indices 0 and 1
    swapCards(thePack, 0, 1);

    // Print the pack after swapping
    printPack("After swapping", thePack);

    bubbleSort(thePack, maxCard); // sort the pack of cards by bubblesort

    // Print the sorted pack
    printPack("Sorted", thePack);

    // Print the number of comparisons and movements
    cout << "Number of comparisons: " << comparisonCount << endl;
    cout << "Number of movements: " << movementCount << endl;

    return 0;
} 
*/

/*
//main for bubblesort 20 times
int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Number of repetitions
    const int repetitions = 2;
    // Repeat the sorting process
    for (int rep = 1; rep <= repetitions; ++rep) {
        // Declare an array to hold the pack of cards
        aCard thePack[maxCard];

        // Populate the pack of cards
        for (int ct = 0; ct < maxCard; ct++)
            thePack[ct] = getCard("32006140"); // student number

        // Print the unsorted pack
        cout << "Iteration " << rep << " - Card Sorting!\n";
        printPack("Unsorted", thePack);

        // Sort the pack
        bubbleSort(thePack, maxCard);

        // Print the sorted pack
        printPack("Sorted", thePack);

        // Print the number of comparisons and movements
        cout << "Number of comparisons: " << comparisonCount << endl;
        cout << "Number of movements: " << movementCount << endl;

        // Reset counters for the next iteration
        comparisonCount = 0;
        movementCount = 0;
    }

    return 0;
}
*/


int partition(aCard thePack[], int low, int high) {
    // Choose middle element as pivot
    aCard pivot = thePack[(low + high) / 2];
    int i = low, j = high;

    while (true) {
        // Move the left pointer to the right until we find an element greater than or equal to the pivot
        while (compareCards(thePack[i], pivot) < 0)
            i++;

        // Move the right pointer to the left until we find an element less than or equal to the pivot
        while (compareCards(thePack[j], pivot) > 0)
            j--;

        // If the pointers cross, the partition is complete
        if (i >= j)
            return j;

        // Swap the elements at the left and right pointers
        swapCards(thePack, i, j);

        // Move the pointers for the next iteration
        i++;
        j--;
    }
}



// Function to implement Quicksort algorithm
void quickSort(aCard thePack[], int low, int high, int currentRecursionLevel) {
    // Update maxRecursionLevel if the current recursion level is greater
    if (currentRecursionLevel > maxRecursionLevel) {
        maxRecursionLevel = currentRecursionLevel;
    }
    // Base case: if 1 or 0 elements in the array 
    if (low < high) {
        // Partition the array into two parts
        int pivotIndex = partition(thePack, low, high);
        // Recursively sort the left and right parts of the partition
        quickSort(thePack, low, pivotIndex, currentRecursionLevel + 1);
        quickSort(thePack, pivotIndex + 1, high, currentRecursionLevel + 1);
    }
}


//main for quicksort
/*
int main() {
    // Seed the random number generator
    srand(time(NULL));

    const int maxCard = 20;

    // Declare an array to hold the pack of cards
    aCard thePack[maxCard];

    // Populate the pack of cards
    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("32006140"); // student number

    // Print the unsorted pack
    cout << "Card Sorting!\n";
    printPack("Unsorted", thePack);

    // Sort the pack using Quicksort
    quickSort(thePack, 0, maxCard - 1, 1);

    // Print the sorted pack
    printPack("Sorted", thePack);

    // Print the number of comparisons, movements, and maximum recursion level
    cout << "Number of comparisons: " << comparisonCount << endl;
    cout << "Number of movements: " << movementCount << endl;
    cout << "Maximum recursion level: " << maxRecursionLevel << endl;

    return 0;
}
*/

//main for both (task9)
/*
int main() {
    const int numIterations = 10; // Number of iterations

    // Seed the random number generator
    srand(time(NULL));

    // Declare an array to hold the pack of cards
    aCard thePack[maxCard];

    // Perform sorting using bubble sort
    cout << "Bubble Sort:\n";
    for (int i = 0; i < numIterations; ++i) {
        // Set seed for random number generator
        srand(i); // Change the seed for each iteration

        // Populate the pack of cards
        for (int ct = 0; ct < maxCard; ct++)
            thePack[ct] = getCard("32006140"); // student number

        // Sort the pack using bubble sort
        bubbleSort(thePack, maxCard);

        // Print the sorted pack
        cout << "Iteration " << i + 1 << ":\n";
        printPack("Sorted", thePack);
    }

    // Perform sorting using quicksort
    cout << "\nQuicksort:\n";
    for (int i = 0; i < numIterations; ++i) {
        // Set seed for random number generator
        srand(i); // Change the seed for each iteration

        // Populate the pack of cards
        for (int ct = 0; ct < maxCard; ct++)
            thePack[ct] = getCard("32006140"); // student number

        // Sort the pack using quicksort
        quickSort(thePack, 0, maxCard - 1, 1);

        // Print the sorted pack
        cout << "Iteration " << i + 1 << ":\n";
        printPack("Sorted", thePack);
    }

    return 0;
}
*/