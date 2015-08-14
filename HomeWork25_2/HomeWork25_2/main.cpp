#include <iostream>
#include "Deck.h"
#include <ctime>

using namespace std;

void main()
{
	srand(time(NULL));
	const int size = 52;	

	Card* card = new Card[size];
	Deck pCard(card);
	pCard->create(pCard);
	pCard->random_mix(pCard);

	if (!(pCard->play(pCard)))
	{
		cout << "\n\npc win\n\n";
	}
	else
	{
		cout << "\n\nplaer win\n\n";
	}

	delete[] card;
}