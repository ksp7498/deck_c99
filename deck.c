#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

#define NUMSUITS 4
#define NUMVALUES 13

int main() {
    deck myDeck = createNewDeck(NUMSUITS, NUMVALUES);
    customizeSuitName(&myDeck, 0, "Hearts");
    customizeSuitName(&myDeck, 1, "Diamonds");
    customizeSuitName(&myDeck, 2, "Clubs");
    customizeSuitName(&myDeck, 3, "Spades");
    shuffleDeck(&myDeck);
    printDeck(myDeck);
    return 0;
}