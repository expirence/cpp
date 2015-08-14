#include "Card.h"
#include <iostream>

using namespace std;


Card::Card()
{
	suit = rank = value = NULL;
}

bool Card::play(Card *card)
{
	static int player_score = 0;
	static int	pc_score = 0;
	char ch = 'y';
	int i = 0;
	//игра игрока
	for (; player_score <= 21; i++)
	{
		cout << "get the card? (y/n): ";
		cin >> ch;
		if (ch == 'n')
			break;
		card[i].print_pack(card, i);//вот здесь выдает ошибку
		player_score += card[i].get_value(card, i);
		if (player_score == 21)
		{
			cout << "!!!BLACK JACK!!!" << endl;
		}
		else if (player_score > 21)
		{
			cout << "too much!" << endl;
		}
		cout << endl;
	}
	cout << endl << endl;
	//игра компа
	for (; pc_score <= 17; i++)
	{
		card[i].print_pack(card, i);
		pc_score += card[i].get_value(card, i);
		if (pc_score == 21)
		{
			cout << "!!!BLACK JACK!!!" << endl;
		}
		else if (pc_score > 21)
		{
			cout << "too much!" << endl;
		}
	}
	if ((player_score > 21) || ((player_score < pc_score) && (pc_score <= 21)))
	{
		return false;
	}
	else if ((player_score == pc_score) || ((player_score > 21) && (pc_score > 21)))
	{
		cout << "draw..." << endl;
	}
	else
		return true;
}
void Card::set_card(int r, int v, int s)
{
	rank = r; value = v; suit = s;
}
//создание колоды
void Card::create(Card* card)
{
	for (int one_pack = 0; one_pack < 1; one_pack++)
		for (int i = 2, m = 0; i < 15; i++)
			for (char j = 3; j < 7; j++, m++)
			{
				short _card = i;
				short _value = i;
				char _suit = j;
				if (i > 10)
					_value = 10;
				if (i == 14)
					_value = 11;
				card[m].set_card(_card, _value, _suit);
			}
}
void Card::print_pack(Card *card, int i)
{
	if (card[i].rank == 11)
	{
		cout << (char)(card[i].rank + 63);
		cout << (char)card[i].suit << " ";
	}
	if (card[i].rank == 12)
	{
		cout << (char)(card[i].rank + 69);
		cout << (char)card[i].suit << " ";
	}
	if (card[i].rank == 13)
	{
		cout << (char)(card[i].rank + 62);
		cout << (char)card[i].suit << " ";
	}
	if (card[i].rank == 14)
	{
		cout << (char)(card[i].rank + 51);
		cout << (char)card[i].suit << " ";
	}
	if (card[i].rank < 11)
	{
		cout << card[i].rank;
		cout << (char)card[i].suit << " ";
	}
}
//значение
int Card::get_value(Card *card, int i)
{
	return card[i].value;
}
//перемешка колоды
void Card::random_mix(Card *card)
{
	short a = 5 + rand() % 6;
	for (short i = 0; i < a; i++)
		for (short j = 0; j < 52; j++)
		{
			Card tmp_mas[1];
			short tmp = 0;
			short a = rand() % 52;
			short b = rand() % 52;
			tmp_mas[tmp] = card[a];
			card[a] = card[b];
			card[b] = tmp_mas[tmp];
		}
}

Card::~Card()
{
}
