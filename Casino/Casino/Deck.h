#pragma once
#include<algorithm>
#include"Card.h"
#include<iostream>
using namespace std;

class Deck
{

	Card _cards[52];
	int _noOfCards;

public:

	Deck()
	{

		int i = 0;

		for (int j = 0; j < 14; j++) {
			for (int k = 0; k < 4; k++) {


				_cards[i].setRank(static_cast<Rank>(j));
				_cards[i].setSuit(static_cast<Suit>(k));

				i++;

				if (i == 52)
					break;
			}
			
			if (i == 52)
				break;
		}

		_noOfCards = 52;
	}

	~Deck()
	{
	}

	void shuffle() {

		random_shuffle(&_cards[0], &_cards[52]);
	}

	Card &deal() {
		
		return _cards[_noOfCards--];
	}

	void resetNoOfCards() {

		_noOfCards = 52;
	}
};