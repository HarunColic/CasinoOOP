#pragma once
#include<iostream>
using namespace std;

enum Suit { Hearts, Spades, Diamonds, Clubs };
char *SuitsChar[] = { "Hearts", "Spades", "Diamonds", "Clubs" };
enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
char *RankChar[] = { "","", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };

class Card
{
	Suit _suit;
	Rank _rank;

public:
	Card()
	{
	}

	Card(Card &C) {

		_suit = C._suit;
		_rank = C._rank;
	}

	Card(Card &&C) {


	}

	~Card()
	{
	}

	void setSuit(Suit suit) {

		_suit = suit;
	}

	void setRank(Rank rank) {

		_rank = rank;
	}

	Rank getRank() {

		return _rank;
	}

	void operator =(Card &C) {

		_suit = C._suit;
		_rank = C._rank;
	}

	friend ostream & operator <<(ostream &COUT, Card &C) {

		COUT << RankChar[C._rank] << endl;
		COUT << SuitsChar[C._suit];

		return COUT;
	}
};