#include <string.h>
#include <time.h>

#define SUITMAXLEN 20

typedef struct {
    int value;
    int suit;
} card;

typedef struct {
    card *cards;
    int decksize;
    char **suits;
} deck;


deck createNewDeck(int numsuits, int numvalues) {
    deck newDeck;
    newDeck.decksize = numsuits * numvalues;
    // alloc suits and cards arrays
    newDeck.suits = calloc(numsuits * sizeof(char*), 1);
    newDeck.cards = calloc(newDeck.decksize * sizeof(card), 1);
    int i=0,j=0,counter=0;
    for (i = 0; i < numsuits; i++) {
        for (j = 0; j < numvalues; j++) {
            // generate each card combination
            newDeck.cards[counter].value = j;
            newDeck.cards[counter].suit = i;
            counter++;
        }
        // alloc a string to hold each suit in the list of suits and set a default value
        newDeck.suits[i] = calloc(SUITMAXLEN, 1);
        sprintf(newDeck.suits[i], "Suit%d", i);
    }
    return newDeck;
}
 
int customizeSuitName(deck *inputDeck, int index, char *newName) {
    // allows replacing the name of a suit with something else.
    // return 0 = success, 1 = error
    if (strnlen(newName, SUITMAXLEN) == SUITMAXLEN) return 1;
    strncpy(inputDeck->suits[index], newName, SUITMAXLEN - 1);
    return 0;
}

void shuffleDeck(deck *inputDeck) {
    time_t t;
    srand(time(&t));
    int i, a, b;
    card temp;
    for (i = 0; i < 1000; i++) {
        a = rand() % inputDeck->decksize;
        b = rand() % inputDeck->decksize;
        // memcpy does not allow source and destination regions to overlap so we
		// can only swap if a != b, in other words can't swap a card with itself
        if (a != b) {
            memcpy(&temp, &(inputDeck->cards[a]), sizeof(card));
            memcpy(&(inputDeck->cards[a]), &(inputDeck->cards[b]), sizeof(card));
            memcpy(&(inputDeck->cards[b]), &temp, sizeof(card));
        }
		// if a == b, decrement i once so we re-do this swap attempt. this makes sure
		// we do 1000 actual swaps instead of wasting some when a == b
		else {
			i--;
		}
    }
}

char* getNameFromCardValue(int cardvalue) {
	switch (cardvalue) {
		case 0:
			return "Ace";
			break;
		
		case 1:
			return "Two";
			break;
		
		case 2:
			return "Three";
			break;
		
		case 3:
			return "Four";
			break;
		
		case 4:
			return "Five";
			break;
		
		case 5:
			return "Six";
			break;
		
		case 6:
			return "Seven";
			break;
		
		case 7:
			return "Eight";
			break;
		
		case 8:
			return "Nine";
			break;
		
		case 9:
			return "Ten";
			break;
		
		case 10:
			return "Jack";
			break;
		
		case 11:
			return "Queen";
			break;
		
		case 12:
			return "King";
			break;
		
		default:
			return "Unknown";
			break;
	}
}


void printDeck(deck inputDeck) {
    int i;
    printf("%d cards:\n----------------------------------------\n", inputDeck.decksize);
    for (i = 0; i < inputDeck.decksize; i++) {
        printf("%s of %s\n", getNameFromCardValue(inputDeck.cards[i].value), inputDeck.suits[inputDeck.cards[i].suit]);
    }
}

