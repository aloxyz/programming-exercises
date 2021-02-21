#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAMESIZE 32
#define DECKSIZE 6

//color type enumeration
typedef enum {
  RED,
  GREEN,
  BLUE,
  YELLOW
} Color;

//number type enumeration
//typedef enum {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} Number;

//card type
typedef struct {
    Color col;
    int num;
} Card;

//node type, represents a card in a list of cards
typedef struct Node {
    int id;
    Card card;
    struct Node *next;
} Node;

//player type
typedef struct {
    char name[NAMESIZE];
    Node *deck;
} Player;

//go to last card
Node *getLast(Node *head){
    Node *tmp = head;
    while (tmp->next != NULL)
	tmp = tmp->next;

    return tmp;
}

//get node on position n
Node *getNode(Node *head, unsigned int n) {
    Node *tmp = head;
    for(int i = 0; i < n; i++) {
      if(tmp->next == NULL)
	NULL;
      tmp = tmp->next;
    }
    return tmp;
}

//get list length
int llen(Node *head) {
    int i = 1;
    Node *tmp = head;
    while(tmp->next != NULL) {
	tmp = tmp->next;
	i++;
    }
    return i;
}

//push n cards
Node* initDeck(int n) {
    Node *head = NULL;
    Node *prev = NULL;
    Node *new = NULL;
    for(int i = 0; i < n; i++) {
	new = (Node *)malloc(sizeof(Node));
	new->id = i;
	new->card.col = rand() % 4;
	new->card.num = rand() % 10;

	if (head == NULL) {
	  head = new;
	}

	if (prev != NULL) {
	  prev->next = new;
	}

	prev = new;
    }
    return head;
}

//return color name as string
char *getColor(Card card) {
    switch(card.col) {
	default:
	case 0:
	  return "red";
	case 1:
	  return "green";
	case 2:
	  return "blue";
	case 3:
	  return "yellow";
    }
}

//print the deck
void printDeck(Node *deck){
    for (int i = 0; i < llen(deck); i++) {
      Card card = getNode(deck, i)->card;
	printf("id: %d, color: %s, number: %d\n", getNode(deck, i)->id, getColor(card), card.num);
    }
}

//initialize player
void initPlayer(Player *player, char *name) {
    Node* deck = initDeck(DECKSIZE);
    player->deck = deck;
    strcpy(player->name, name);
}

int main() {
    srand(time(NULL));

    Player user1, user2;
    initPlayer(&user1, "aloxyz");
    initPlayer(&user2, "computer");

    printf("%s\n", user1.name);
    printDeck(user1.deck);

    printf("%s\n", user2.name);
    printDeck(user2.deck);

}
