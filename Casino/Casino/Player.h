#pragma once
#include<iostream>
#include"Card.h"
using namespace std;


class Player
{
	char *_name;
	Card _cards[5];
	int _noOfCards;
	int _handSum; //only used in Black Jack

public:

	Player()
	{
		_name = nullptr;
		_noOfCards = 0;
		_handSum = 0;
	}

	Player(char *name) {

		_name = new char[strlen(name) + 1];
		strcpy_s(_name, strlen(name) + 1, name);

		_noOfCards = 0;

		_handSum = 0;
	}

	Player(Player &P) {

		if (_name != nullptr) {

			delete[] _name;
			_name = nullptr;
		}

		_name = new char[strlen(P._name) + 1];
		strcpy_s(_name, strlen(P._name) + 1, P._name);

		_noOfCards = P._noOfCards;

		for (int i = 0; i < _noOfCards; i++) {

			_cards[i] = P._cards[i];
		}

		_handSum = P._handSum;
	}

	~Player()
	{

		delete[] _name;
		_name = nullptr;
	}

	void handOneCard(Card _card, int choice) {

		if (choice == 1) {
			if (_noOfCards == 5) {

				cout << "Failed! Player has the maximum number of cards" << endl;
				return;
			}

			_cards[_noOfCards] = _card;
			cout << "Card handed" << endl;
			_noOfCards++;
		}
		else {
			
			_cards[_noOfCards] = _card;
			cout << "Card handed" << endl;
			_noOfCards++;

			if ((int)_card.getRank() <= 10)
				_handSum += (int)_card.getRank();
			else
				_handSum += 10;
		}
	}

	void checkhand(int choice) {

		for (int i = 0; i < _noOfCards; i++) {

			cout << "-------------" << endl;
			cout << _cards[i] << endl;
			cout << "-------------" << endl;
		}

		if (choice == 1) {
			int counter = 0;

			for (int i = 0; i < _noOfCards - 1; i++) {
				for (int j = 1; j < _noOfCards; j++) {

					if (_cards[i].getRank() == _cards[j].getRank())
						counter++;
				}

				if (counter == 2) {

					cout << "The player has a pair of " << RankChar[_cards[i].getRank()] << endl;
				}
				else if (counter == 3) {

					cout << "The player has trip " << RankChar[_cards[i].getRank()] << endl;
				}
				else if (counter == 4) {

					cout << "The player has quad " << RankChar[_cards[i].getRank()] << endl;
				}
			}
		}
		else {

			cout << "Total: " << _handSum << endl;
		}
	}

	int getHandSum() {

		return _handSum;
	}

	int getDealerHandSum(Deck &D) {

		int sum = 0;

		do
		{

			sum += (int)D.deal().getRank();

			if (sum == 21)
				return sum;

		} while (sum<17);

		return sum;
	}
};