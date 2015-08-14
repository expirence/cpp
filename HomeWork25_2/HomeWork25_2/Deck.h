#pragma once
#include "Card.h"
class Deck
{
	//указаьель на класс  арта
	Card* ptr;
public:
	//конструктор класса колода
	Deck(Card* card = nullptr);
	~Deck();
	// оператор преобразовани€ типа от инкапсулированного к инкапсулирующему
	operator Card*(){
		return ptr;
	}
	// ќператор селектора -> который позволит обратитьс€ 
	// напр€мую к спр€танному указателю
	Card* operator->(){
		return ptr;
	}
};

