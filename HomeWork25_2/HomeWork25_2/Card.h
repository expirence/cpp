#pragma once

class Card
{
	// ����� �����
	int suit;
	// ����������� �����
	int rank;
	// �������� �����
	int value;
public:
	//����������� ������ �����
	Card();
	~Card();
	//����
	bool play(Card *card);
	// ������������ �����
	void set_card(int r, int v, int s);
	//�������� ������
	void create(Card* card);
	// ��������� ������
	void random_mix(Card *card);
	// ������ ������
	void print_pack(Card *card, int i);
	//��������
	int get_value(Card *card, int i);
};

