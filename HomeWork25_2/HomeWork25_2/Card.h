#pragma once

class Card
{
	// масть карты
	int suit;
	// достоинство карты
	int rank;
	// значение карты
	int value;
public:
	//конструктор класса карта
	Card();
	~Card();
	//игра
	bool play(Card *card);
	// формарование карты
	void set_card(int r, int v, int s);
	//создание колоды
	void create(Card* card);
	// перемешка колоды
	void random_mix(Card *card);
	// печать колоды
	void print_pack(Card *card, int i);
	//значение
	int get_value(Card *card, int i);
};

