#pragma once
#include "Card.h"
class Deck
{
	//��������� �� ����� �����
	Card* ptr;
public:
	//����������� ������ ������
	Deck(Card* card = nullptr);
	~Deck();
	// �������� �������������� ���� �� ������������������ � ����������������
	operator Card*(){
		return ptr;
	}
	// �������� ��������� -> ������� �������� ���������� 
	// �������� � ����������� ���������
	Card* operator->(){
		return ptr;
	}
};

